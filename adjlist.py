


class graph:
    def __init__(self,v):
        self.v=v
        self.edge=[]
        self.list=None
        self.adj_matrix=[[0 for i in range(self.v)] for j in range(self.v)]
        self.adj=[False for i in range(self.v)]
        self.color=[-1 for i in range(self.v)]

        
    def addedge(self,u,d):
        if u==d:
            self.edge.append([u,d])
        else:

            self.edge.append([u,d])
            self.edge.append([d,u])

    
    def adlist(self):
        adj_list={key:[] for key in range(self.v)}
        for edges in self.edge:
            edge_val=edges[1]
           

            adj_list[edges[0]].append(edge_val)

        self.list=adj_list

    def printing(self):
        for key,value in self.list.items():
            print(key,value,end=" ")
            print("")
            
            

    def adjmatrix(self,u,d):
        

        self.adj_matrix[u][d]=1
        self.adj_matrix[d][u]=1


    def bfs(self,s):
        self.adj[s]=True
        queue=[]
        queue.append(s)
        while queue:
            t=queue.pop(0)
            print(t,end=" ")
            for value in self.list[t]:
                
                if self.adj[value]==False:
                    queue.append(value)
                    self.adj[value]=True



    def bipartite(self,s):
        self.color[s]=1
        queue=[]
        queue.append(s)
        while(queue):
            sp=queue.pop(0)
            for i in range(self.v):
                if self.adj_matrix[i][i]==1:
                    return False
                elif self.adj_matrix[sp][i]==1 and self.color[i]==-1:
                    self.color[i]=1-self.color[sp]
                    queue.append(i)

                elif self.adj_matrix[sp][i]==1 and self.color[i]==self.color[sp]:
                    return False
        return True







    def printmatrix(self):
        for i in range(self.v):
            for j in range(self.v):
                print(self.adj_matrix[i][j],end = ' ')
            print("")










def main():

    print("Enter the no of vertices")
    v=int(input())

    g=graph(v)
    print("Enter no of edges")
    n=int(input())
    print("Enter the vertices having an edge")

    for i in range(n):
        u=input()
        v=input()
        u,v=int(u),int(v)
        g.addedge(u,v)
        g.adjmatrix(u,v)

    g.adlist()
    g.printing()
    g.printmatrix()
    print("Enter the source vertex :")
    s=int(input())
    g.bfs(s)
    print(g.bipartite(s))







if __name__ == '__main__':
	main()