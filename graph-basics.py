from collections import deque
class graph:
    def __init__(self,G):
        self.list=G
        self.visited=[0 for i in range(len(self.list))]
        self.ls=[]
        self.color=[-1 for i in range(len(self.list))]
        self.ad_matrix=[[0 for i in range(len(self.list))] for j in range(len(self.list))]
        self.dist=[0 for i in range(len(self.list))]
        self.vis=[0 for i in range(len(self.list))]
        self.lp=[]
        self.start=[0 for i in range(len(self.list))]
        self.finish=[0 for i in range(len(self.list))]
        self.time=0
        self.conn=[0 for i in range(len(self.list))]

        self.temp=0

    def listing(self):
        for i in range(len(self.list)):
            lt=self.list[i]
            for j in lt:
                
                self.ad_matrix[i][j]=1
    def printing(self):
        print("\n")
        for i in range(len(self.list)):

            for j in range(len(self.list)):
                print(self.ad_matrix[i][j],end=' ')
            print("")

    def bfs(self,s):
        #for bunch in range(self.list):
            queue=deque([])
            queue.append(s)
            self.dist[s]=0
            self.visited[s]=1
            while(queue):
                sp=queue.popleft()
                print(sp,end=" ")
                self.ls=self.list[sp]
                
                for i in (self.ls):

                    if self.visited[i]==0:
                        self.dist[i]=self.dist[sp]+1
                        queue.append(i)
                        self.visited[i]=1


    def distance(self):
        for i in range(len(self.dist)):
            print(self.dist[i],end=" ")



    def bipartite(self,s):
        queue=deque([])
        queue.append(s)
        self.color[s]=0
        while queue:
            s=queue.popleft()

            for i in range(len(self.list)):
                if self.ad_matrix[s][i]==1 and self.color[s]!=self.color[i]:


                    self.color[i]=1-self.color[s]
		    queue.append(i)
                elif self.ad_matrix[s][i]==1 and self.color[s]==self.color[i]:
                    return False
            return True
    
    def dfs(self,s):

        self.vis[s]=1
        self.start[s]=self.time
        self.time=self.time+1
        self.lp=self.list[s]
        print(s,end=" ")
        self.conn[s]=self.temp

        for i in self.lp:
            if self.vis[i]==0:
                self.dfs(i)
        self.finish[s]=self.time
        self.time=self.time+1

    def timing(self):
        print("\n")
        print("Starting time-stamp are:")
        for i in range(len(self.start)):
            print(self.start[i],end=" ")

        print("\n")
        print("Finishing time-stamp are:")
        for j in range(len(self.finish)):
            print(self.finish[j],end=" ")

    def connectedcom(self):
        print("\n")
        self.temp=self.temp+1
        for i in range(len(self.conn)):
            if self.conn[i]==0:
                self.dfs(i)
            self.temp=self.temp+1

        #print(self.conn)





def main():
    
    G = [] 
    

    file=open('input.txt','r')
    for line in file:
    
        line=line.strip()
    
        adjacentVertices = []
        first=True
        for node in line.split(' '):
            if first:
                first=False
                continue
            adjacentVertices.append(int(node))

        G.append(adjacentVertices)

    file.close()

    print(G)
    g=graph(G)


    print("Enter the source vertex")
    s=int(input())
    g.bfs(s)
    g.listing()
    g.printing()
    print("Distance from the given vertex is")
    g.distance()
    print("\n")
    if(g.bipartite(0)):
        print("The given graph is bipartite")
    else:
        print("Not a bipartite graph")
    print("Enter the source vertex for dfs:")
    s=int(input())
    print("Dfs of the given graph is:")
    g.dfs(s)
    g.timing()
    g.connectedcom()

if __name__ == '__main__':
    main()

