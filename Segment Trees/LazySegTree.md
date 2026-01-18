# Lazy Segment Tree 

## Invariant (MOST IMPORTANT)

* When you are at `node`, **all parents are already pushed**
* `st[node]` is **always correct**
- `lazy[node]` represents the operation that still needs to be propagated to the children (it has ALREADY been applied to `st[node]`)
---

## apply(node, lz)


```
st[node]   += effect(lz on this segment)
lazy[node] += lz
```

* `lazy[node]` is already reflected in `st[node]` when its parent did push.
* ❌ Never apply `lazy[node]` to `st[node]` again

---

## push(node)

**Send pending work to children**

```
apply(left,  lazy[node])
apply(right, lazy[node])
lazy[node] = 0
```

- https://atcoder.jp/contests/abc441/tasks/abc441_g
