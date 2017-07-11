import heapq

class edge:
    def __init__(self,to,cap,cost,rev):
        self.to = to
        self.cap = cap
        self.cost = cost
        self.rev = rev

class min_cost_flow:
    INF = 52**60
    def __init__(self, n):
        self.V = n
        self.G = [[] for _ in range(n)]
        self.h = [0 for _ in range(n)]
        self.dist = [0 for _ in range(n)]

    def add_edge(self, f, t, cap, cost):
        self.G[f].append(edge(t,cap,cost,len(self.G[t])))
        self.G[t].append(edge(f,0,-cost,len(self.G[f])-1))

    def min_cost_flow(self, s, t, f):
        prevv = [0 for _ in range(self.V)]
        preve = [0 for _ in range(self.V)]

        res = 0
        self.h = [0 for _ in range(self.V)]
        while f > 0:
            pq = []
            self.dist = [min_cost_flow.INF for _ in range(self.V)]
            self.dist[s] = 0
            # dijkstra
            heapq.heappush(pq,(0,s))
            while len(pq) != 0:
                p = heapq.heappop(pq)
                v = p[1]
                if p[0] > self.dist[v]:
                    continue
                for i in range(len(self.G[v])):
                    e = self.G[v][i]
                    if e.cap>0 and self.dist[e.to]>self.dist[v]+e.cost+self.h[v]-self.h[e.to]:
                        self.dist[e.to] =  self.dist[v]+e.cost+self.h[v]-self.h[e.to]
                        prevv[e.to] = v
                        preve[e.to] = i
                        heapq.heappush(pq,(self.dist[e.to],e.to))

            if self.dist[t] == min_cost_flow.INF:
                return -1

            for i in range(self.V):
                self.h[i] += self.dist[i]

            d = f
            v = t
            while v != s:
                d = min(d,self.G[prevv[v]][preve[v]].cap)
                v = prevv[v]
            f -= d
            res += d*self.h[t]

            v = t
            while v != s:
                self.G[prevv[v]][preve[v]].cap -= d
                self.G[v][self.G[prevv[v]][preve[v]].rev].cap += d
                v = prevv[v]

        return res
