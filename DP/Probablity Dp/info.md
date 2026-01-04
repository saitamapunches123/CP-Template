# Probability / Expectation DP

## Core Formula

```text
dp[state] = Σ P(state → next) · dp[next]
```

This comes from **expected value (law of total expectation)**.

---

## Two Types of Questions

### 1️⃣ Probability DP

**Meaning of `dp[state]`:**
Probability that a certain event happens starting from `state`.

**Example meanings:**

* Probability of a knight going of knight going off the chess board in k moves
* Probability of winning the game

**Base cases:**

* Success state → `dp = 1`
* Impossible / failure state → `dp = 0`

---

### 2️⃣ Expectation DP

**Meaning of `dp[state]`:**
Expected value (steps / cost / score / time) starting from `state`.

**Typical form:**

```text
dp[state] = immediate_cost + Σ P(state → next) · dp[next]
```

**Example meanings:**

* Expected number of moves
* Expected cost to finish

---

## One-Line Rule

> **`dp[state]` = expected final answer assuming you start from this state.**


## Graph representation

* Vertice => state
* Edge => transition
* Egde Weight => probablity of transition
* P.S => sum of all outgoing edge weigths form each vertex must be one (Something must happen)
* Σ P(state → next) = 1

## P.S HEURESTIC APPROXIMATION:

* If constratints are too big to make dp, Check if probablity is strictly increasing or decreasing with n ( Transitions are biased towards 1 event)
* If Probablity is strictly increastion or decreasing for big constrainsts we can return 1 or 0 directly without computing (APPROXIMATION)
* For example: https://leetcode.com/problems/soup-servings/description/
* Here transition are biased for A to finish first

## P.S INFINITE LOOP CASE:

* if in dp relation dp[x] depends on dp[x] this looks like infinite loop so cant use recurstion but we can use maths
* as for example: dp[x] =1+p*dp[x-1]+(1-p)*dp[x] => dp[x]*p=1+p*dp[x-1] => dp[x]=1/p+dp[x-1]
* Now we can use recurstion (or iterative dp) to solve. Thus by rearanging our recurence relation we can avoid infinite loop 
