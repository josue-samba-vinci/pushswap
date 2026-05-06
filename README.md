*This project has been created as part of the 42 curriculum by josamba-, tmatttela*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal
is to sort a list of integers in ascending order on stack `a` using a second
stack `b` and a restricted set of operations, producing the **smallest possible
sequence of operations** to perform the sort.

The project enforces a concrete understanding of **algorithmic complexity**:
the cost we measure is not CPU time but the **number of `push_swap`
operations** generated to sort the input. Four sorting strategies are embedded
in the binary, each one targeting a specific complexity class, plus an
**adaptive** strategy that picks the right one according to a `disorder`
metric computed on the input.

### Available operations

`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

## Instructions

### Compilation

```bash
make          # builds ./push_swap
make clean    # removes .o files
make fclean   # removes .o files and the binary
make re       # fclean + all
```

The Makefile compiles with `-Wall -Wextra -Werror` and builds the embedded
`ft_printf` library located in [src/utils/printf/](src/utils/printf/).

### Usage

```
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] <int1> <int2> ...
```

- The arguments form the initial stack `a`, the **first argument being the
  top** of the stack.
- If no integer is given, the program exits silently.
- Invalid input (non-integer, value out of `int` range, duplicates) prints
  `Error\n` on `stderr`.
- If the stack is already sorted, nothing is printed.

### Strategy flags

| Flag          | Strategy                     | Complexity     |
|---------------|------------------------------|----------------|
| `--simple`    | Selection sort adaptation    | O(n²)          |
| `--medium`    | Chunk-based sort (√n chunks) | O(n√n)         |
| `--complex`   | Radix sort (LSD, binary)     | O(n log n)     |
| `--adaptive`  | Picks one of the above       | depends on disorder |

When no flag is given, the **adaptive** strategy runs by default.

### Benchmark mode

`--bench` prints sorting metrics on `stderr` after the operation stream:

- The computed `disorder` (in %).
- The strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
  `rr`, `rra`, `rrb`, `rrr`).

```bash
$> ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt
$> cat bench.txt
[bench] Disorder     : 40.00%
[bench] Strategy     : Adaptive / O(n√n)
[bench] Total ops    : 13
...
```

## Project structure

```
include/push_swap.h          → public types and prototypes
src/main.c                   → entry point, dispatch to the chosen strategy
src/parser.c                 → integer parsing and validation
src/flags.c                  → flag parsing and benchmark printing
src/compute_disorder.c       → disorder metric (mandatory)
src/operations/              → sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
src/sorting/simple_sort.c    → O(n²) selection-sort adaptation
src/sorting/medium_sort.c    → O(n√n) chunk-based sort
src/sorting/complex_sort.c   → O(n log n) radix sort
src/sorting/three_sort.c     → hard-coded sort for n ≤ 3
src/utils/                   → linked-list helpers, ft_split, ft_atoi, etc.
src/utils/printf/            → custom ft_printf used by the project
```

## Algorithms

### Disorder metric

Implemented in [src/compute_disorder.c](src/compute_disorder.c). For every
pair `(i, j)` with `i < j` in the initial stack, a pair counts as a *mistake*
when `a[i] > a[j]`. `disorder = mistakes / total_pairs`. The value lies in
`[0, 1]`: `0` means already sorted, `1` means reverse-sorted. It is computed
**before any operation** is generated, and only when needed (adaptive mode or
`--bench`).

### 1. Simple — Selection sort, O(n²)

[src/sorting/simple_sort.c](src/sorting/simple_sort.c). At each step we look
for the minimum of `a`, rotate it to the top using the shortest direction
(`ra` or `rra`), and `pb` it onto `b`. When `a` has 3 elements left, we apply
the hard-coded `three_sort`, then push everything back from `b` to `a`.
Generates O(n²) operations in the worst case but stays simple and predictable
for low-disorder inputs.

### 2. Medium — Chunk-based sort, O(n√n)

[src/sorting/medium_sort.c](src/sorting/medium_sort.c). The values of `a` are
first **indexed** (replaced by their rank in `[0, n[`), then split into
`√n` chunks of `√n` values each. We scan `a`, rotating the closest chunk
member to the top and pushing it to `b`. While doing so, larger values
already in `b` are kept sorted by choosing between `rb` and `rrb` to drop
each new value at the right spot. Once `a` is empty, `b` is in descending
order: we just push everything back, choosing the cheapest rotation for the
current maximum. Total work is bounded by O(n√n) operations.

### 3. Complex — Radix sort (LSD, binary), O(n log n)

[src/sorting/complex_sort.c](src/sorting/complex_sort.c). Values are indexed
(`0..n-1`) so we know we only need `⌈log₂(n)⌉` bits. For each bit, we walk
the stack once: if the current bit is `1` we `ra`, otherwise we `pb`. After
each pass everything in `b` is pushed back to `a`. After `log₂(n)` passes the
stack is sorted. Total operations are bounded by `n × log₂(n)`, which fits
the project's 100/500-element targets comfortably.

### 4. Adaptive

Routed by `launch_algo` in [src/main.c](src/main.c#L36) using the `disorder`
value:

| Disorder           | Strategy chosen | Complexity   |
|--------------------|-----------------|--------------|
| `< 0.2`            | simple          | O(n²)        |
| `0.2 ≤ d < 0.5`    | medium          | O(n√n)       |
| `≥ 0.5`            | complex         | O(n log n)   |

**Rationale for the thresholds.** When the input is almost sorted
(`d < 0.2`), the constants of selection sort dominate and it produces the
shortest sequence. For moderately shuffled inputs (`0.2 ≤ d < 0.5`), the
chunked approach amortises movements better. For highly shuffled inputs
(`d ≥ 0.5`), only the radix sort scales correctly and stays well under the
operation budget.

For `n ≤ 3`, the dispatcher in `main` skips the chosen strategy and calls
`three_sort` directly, since the optimal sequence for small inputs is
hard-coded.

## Error handling

`Error\n` is printed on `stderr` for any of the following:

- A non-integer argument.
- An integer that does not fit in `int` (`INT_MIN` / `INT_MAX`).
- A duplicate value in the input.
- Empty argument.

In every error case, no operation is printed.

## Contributors

This project is a **mandatory group project (2 learners)** of the 42 cursus.

- **josamba-** — chunk-based medium sort, radix-based complex sort,
  associated utilities (`index_stack`, `medium_sort_utils`, `ft_sqrt`,
  chunk helpers).
- **tmatttela** — project skeleton (Makefile, parsing, stack & list
  utilities), stack operations (`sa`/`sb`/`pa`/`pb`/`ra`/`rb`/`rra`/`rrb`
  and their combined variants), `three_sort`, simple selection sort,
  disorder metric, flag parsing and `--bench` output.

Both authors discussed and reviewed every algorithm together; we are both
able to explain and defend any part of the codebase during the defense.

## Resources

- *The Art of Computer Programming, Vol. 3 — Sorting and Searching*,
  Donald E. Knuth.
- Radix sort, Wikipedia: <https://en.wikipedia.org/wiki/Radix_sort>
- Chunk / bucket sort discussions on the 42 community wikis.
- 42 Norm reference for code-style requirements.

### AI usage

AI tools (ChatGPT / Claude) were used as a **support tool**, never as a code
generator we could not justify ourselves. Concretely:

- Brainstorming the right thresholds for the adaptive strategy and
  understanding why a radix sort fits the `push_swap` operation model better
  than a quick sort for large `n`.
- Clarifying the formal definition of the `disorder` metric (inversion count
  normalised by `n(n-1)/2`).
- Reviewing tricky parts of the chunk-based sort to spot off-by-one errors
  on rotation choices.
- Rephrasing the present README for clarity.

Every algorithm, data structure and line of code committed to this
repository was written, debugged and tested by the two authors and is fully
understood by both of them.
