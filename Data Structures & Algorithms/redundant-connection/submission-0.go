type UnionFind struct {
    parent map[int]int
    rank map[int]int
}

func NewUnionFindInstance(n int)*UnionFind{
    
    instance := &UnionFind{
        parent: make(map[int]int, n + 1),
        rank: make(map[int]int, n + 1),
    }

    for i := range n + 1  {
        instance.parent[i] = i
        instance.rank[i] = 1
    }

    return instance
}

func (uf *UnionFind) Find(x int) int {
    if uf.parent[x] != x {
        uf.parent[x] = uf.Find(uf.parent[x])
    }
    return uf.parent[x]
}

func (uf *UnionFind) UnionFind(x,y int) bool {
    px, py := uf.Find(x), uf.Find(y)
    if px == py {
        return false
    }

    if uf.rank[px] > uf.rank[py] {
        uf.parent[py] = px
        uf.rank[px] += uf.rank[py]
    } else {
        uf.parent[px] = py
        uf.rank[py] += uf.rank[px]
    }

    return true
}

func findRedundantConnection(edges [][]int) []int {
    
    ufInstance := NewUnionFindInstance(len(edges))
    
    for i := range len(edges) {
        from, to := edges[i][0], edges[i][1]
        if !ufInstance.UnionFind(from,to) {
            return []int{from, to}
        }
    }

    return []int{}    
}
