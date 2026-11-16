*This project has been created as part of the 42 curriculum by kisella, tobillet.*

# ft_push_swap

## Description

`push_swap` sorts a stack of integers passed as arguments, using only two stacks (`a` and
`b`) and eleven operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`,
`rrr`). It prints on the standard output the sequence of operations that sorts stack `a`
in ascending order (smallest element on top), with as few operations as possible.

Four strategies are embedded in a single binary and can be selected at runtime:

| Selector | Strategy | Operation complexity |
|----------|----------|----------------------|
| `--simple` | selection sort adapted to two stacks | O(n²) |
| `--medium` | chunk-based partitioning | O(n√n) |
| `--complex` | LSD radix sort on ranks | O(n log n) |
| `--adaptive` | picks one of the above from the measured disorder (default) | regime-dependent |

The complexity is always counted in **Push_swap operations generated**, not in the
theoretical cost of an array-based algorithm, as the subject requires. The disorder
metric of the subject (proportion of inverted pairs) is computed once, before any move,
and drives the adaptive strategy.

## Instructions

### Compilation

```sh
make        # builds ./push_swap, compiled with cc -Wall -Wextra -Werror
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + make
```

The bundled `Libft` is compiled through its own Makefile and linked to the binary.

### Usage

```sh
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

- The strategy selector is optional; `--adaptive` is used by default. Every selector works
  for any valid input, whatever its size or disorder.
- Integers can be given as separate arguments or grouped in one quoted string:
  `./push_swap "3 2 1"` and `./push_swap 3 2 1` behave identically. The first argument is
  the top of stack `a`.
- Operations are printed on **stdout**, one per line and nothing else.
- `--bench` prints the benchmark on **stderr**: disorder (two decimals), strategy name and
  its theoretical complexity class on the same line (`Adaptive / O(n√n)`), total number of
  operations and the count of each operation type. stdout still contains only the
  operations.
- With no argument, nothing is printed and the prompt comes back.
- Invalid input (non-integer, value outside the `int` range, duplicate, unknown flag)
  prints `Error` followed by a newline on **stderr** and exits with status 1.

### Examples

```console
$ ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa

$ ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
13

$ ./push_swap --bench 2 1 3 6 5 8 2>&1 >/dev/null
[bench] disorder: 13.33%
[bench] strategy: Adaptive / O(n²)
[bench] total_ops: 16
[bench] sa: 0 sb: 0 ss: 0 pa: 6 pb: 6
[bench] ra: 3 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0

$ ./push_swap --adaptive 0 one 2 3
Error
```

## Algorithms

Complexity is always expressed in **number of Push_swap operations generated**, never in
the theoretical cost of an equivalent array-based algorithm, as required by the subject.

### Shared groundwork

**Parsing and validation** (`parsing.c`, `parsing_numbers.c`, `parsing_int.c`)
Each argument is split on spaces/tabs, converted digit by digit and checked against
`INT_MAX`/`INT_MIN` *during* the conversion, so `2147483648` is rejected without any
overflow. Duplicates are detected with an O(n²) scan. On failure everything already
allocated is freed and `Error` is printed on stderr.

**Ranking** (`stack_rank.c`)
Once the input is valid, every value is replaced by its rank in `0 .. n-1`. This
normalises arbitrary, negative or extreme inputs and gives the radix sort small
non-negative integers to work with. Ranking costs O(n²) time and O(n) extra space (one
temporary copy of the stack).

**Disorder metric** (`disorder.c`)
Exactly the metric of the subject: every pair `(i, j)` with `i < j` is examined, each
pair where `a[i] > a[j]` is a mistake, and the disorder is `mistakes / (n(n-1)/2)`
(0 for a sorted stack, 1 for a reverse-sorted one). It is measured **before any move**,
in O(n²) time and O(1) memory.

### Simple — O(n²) (`algo_simple.c`, `algo_selection.c`)

- For `n <= 5`, dedicated move sequences (`sort_three`, `sort_four`, `sort_five`) are
  cheaper than any generic loop.
- For `n > 5`, a **selection sort adapted to two stacks**: for each rank `0 .. n-1`,
  stack `a` is rotated by the shortest path (`ra` if the rank is in the first half,
  `rra` otherwise) to bring that rank on top, then `pb`. Stack `b` is therefore filled in
  increasing order, and pushing everything back with `pa` rebuilds `a` sorted.

**Complexity:** one extraction costs at most `n/2` rotations plus one push, so the `n`
extractions cost at most `n²/2 + n`, and the final `pa` loop adds `n`: O(n²) operations,
about `n²/8 + 2n` on random input. **Space:** O(1) extra, the stacks are modified in
place.

### Medium — O(n√n) (`algo_medium.c`)

Chunk-based partitioning:

1. Scan `a`. A value `<= i + range` (`i` being the number of elements already pushed) is
   pushed to `b`; a value `<= i`, i.e. the current minimum region, is pushed and then
   rotated to the bottom of `b` with `rb`, which starts building the sorted order at the
   bottom. All other values are rotated with `ra` and looked at again later.
2. Repeatedly extract the maximum of `b`, rotating `b` by the shortest path
   (`rb`/`rrb`), and `pa` it, which rebuilds `a` in ascending order.

`range` is 15 for `n <= 100` and 35 above, which keeps the number of chunks close to √n
(about 7 chunks for n = 100 and 15 for n = 500).

**Complexity:** each chunk costs at most one full pass over `a`, i.e. O(n), and there are
O(n / range) chunks with `range = Θ(√n)`, hence O(n√n) operations. **Space:** O(1) extra.

### Complex — O(n log n) (`algo_complex.c`)

**LSD radix sort on the ranks**: for each bit, from least significant to most
significant, the stack is scanned once; elements whose current bit is set are rotated
(`ra`), the others are pushed to `b` (`pb`). Pushing everything back with `pa` restores
the order while grouping zeros before ones, which is exactly one stable radix pass. The
number of passes is `ceil(log2(n))`.

**Complexity:** one pass costs `n` operations plus one `pa` per zero bit (about `n/2`),
and there are `ceil(log2(n))` passes, so O(n log n) operations, deterministic in `n` and
independent of the input order. **Space:** O(1) extra.

### Adaptive (`algo_adaptive.c`)

The disorder is measured once, then the strategy dispatches:

| Condition | Method | Class |
|-----------|--------|-------|
| disorder < 0.2 | selection sort | O(n²) |
| 0.2 ≤ disorder < 0.5 | chunk-based sort | O(n√n) |
| disorder ≥ 0.5 | radix sort | O(n log n) |

Inputs of 5 elements or fewer always use the dedicated `sort_three` / `sort_four` /
`sort_five` sequences, whatever strategy is selected: at that size the generic loops are
never competitive (`2 1` needs exactly one `sa`, not a radix pass). The class printed by
`--bench` stays the one of the regime selected by the disorder, as the subject requires.

**Why these thresholds:** the disorder is the proportion of inverted pairs, i.e. the
amount of work an exchange-based sort will have to do. On a nearly sorted stack
(disorder < 0.2) the selection sort only performs very short rotations and finishes in
about `2n` operations, which beats radix on small and medium inputs. Above 0.2 those
short rotations disappear and the O(n√n) chunk sort becomes clearly better. Above 0.5
(half of all pairs inverted) the input is close to random or reverse-sorted, where the
deterministic O(n log n) radix sort is never beaten. These are exactly the regimes
required by the subject.

**Space:** every strategy works directly on the two linked lists; the only auxiliary
allocation is the single temporary copy used for ranking, so the memory is O(n) for the
stack plus one O(n) transient.

### Measured performance

Random inputs (`seq 1 n | shuf`), 6 runs per strategy, in operation counts:

| n | `--simple` | `--medium` | `--complex` | `--adaptive` |
|---|-----------|-----------|------------|-------------|
| 100 | 1310 – 1571 | 546 – 585 | 1084 | 558 – 1084 |
| 500 | 31039 – 33510 | 4932 – 5095 | 6784 | 5053 – 6784 |

Subject targets: for 100 numbers `< 2000` to pass, `< 1500` good, `< 700` excellent; for
500 numbers `< 12000` / `< 8000` / `< 5500`. The default strategy (`--adaptive`) and
`--medium` land between "good" and "excellent", and `--complex` is deterministic and also
inside the targets (6784 operations for 500 numbers). On nearly sorted inputs
(disorder ≈ 0) the adaptive strategy falls back to the simple sort and needs about `2n`
operations (216 for n = 100, 1038 for n = 500).

## Project structure

```
push_swap.h          shared types and prototypes
main.c               entry point, flag parsing, strategy dispatch, cleanup
parsing*.c           argument validation (integers, overflow, duplicates)
stack*.c             linked-list stack, ranking, sortedness check
disorder.c           inversion-based disorder metric
operations*.c        the 11 Push_swap operations and their counters
algo_simple.c        small-size sorts (n <= 5) and simple dispatcher
algo_selection.c     O(n^2) selection sort used for n > 5
algo_medium.c        O(n sqrt(n)) chunk-based sort
algo_complex.c       O(n log(n)) LSD radix sort
algo_adaptive.c      regime selection based on the measured disorder
bench.c              --bench output (stderr)
get_val.c            position / min / max helpers
Libft/               allowed personal library
Makefile             NAME, all, clean, fclean, re
```

## Contributions

Both learners took part in the design of the strategies and reviewed the whole code base.

- **tobillet (Tom Billet)** — parsing and validation (`parsing.c`, `parsing_numbers.c`,
  `parsing_int.c`), linked-list stacks (`stack.c`, `stack_more.c`, `stack_rank.c`),
  disorder metric (`disorder.c`),  adaptive dispatch (`algo_adaptive.c`), 
  `--bench` output (`bench.c`), `main.c`, build system and Libft integration.

- **kisella (Killian Sella)** — Push_swap operations (`operations.c`), dedicated small-size
  sorts `sort_three` / `sort_four` / `sort_five` (`algo_simple.c`), chunk-based medium
  strategy (`algo_medium.c`), radix sort (`algo_complex.c`), value helpers (`get_val.c`), 
  shared header and Makefile.

## Resources

Documentation and references used to design and verify the algorithms:

- *Push_swap* subject, version 1.2 (42 curriculum) — rules, disorder metric, complexity
  targets.
- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein,
  *Introduction to Algorithms*, MIT Press — sorting algorithms and complexity analysis.
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting algorithm — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
- [Valgrind manual](https://valgrind.org/docs/manual/manual.html) — memory checks.

### AI usage

AI was used for the following tasks:

- drafting and structuring this README;
- code review and debugging of the mandatory part;

The algorithms themselves were designed and implemented by the two learners. Every
AI-assisted change was reviewed, tested on all four strategies from 1 to 500 elements,
and is understood by both of them, who remain responsible for the whole code base.