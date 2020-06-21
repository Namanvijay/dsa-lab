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
        self.ti=0
        self.conn=[0 for i in range(len(self.list))]
        self.flg=0
        self.flag=0
        self.arr=[0 for i in range(len(self.list))]
        self.visi=[0 for i in range(len(self.list))]
        self.bridge_edge=[]

        self.low=[0 for i in range(len(self.list))]

        self.dis=[0 for i in range(len(self.list))]
        self.parent=[0 for i in range(len(self.list))]
        self.color1=[-1 for i in range(len(self.list))]
        self.color1[0]=0
        

        

        self.temp=0
        self.tree_edge=[]
        self.back_edge=[]  

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
                if self.ad_matrix[s][i]==1 and self.color[i]==-1:
                    self.color[i]=1-self.color[s]
                    queue.append(i)
                elif self.ad_matrix[s][i]==1 and self.color[s]==self.color[i]:
                    return False
            return True

    def bipartite_dfs(self,s):
        
        
        self.ls=self.list[s]
        for i in self.ls:
            if self.color[i]==-1:
                self.color[i]=1-self.color[s]
                if(self.bipartite_dfs(i)==False):
                    return False
            elif self.color[i]==self.color[s]:
                return False
        return True
    
    
    def dfs(self,s):
        
        self.vis[s]=1
        self.start[s]=self.time
        self.time=self.time+1
        self.lp=self.list[s]
        if self.flg==0:
            print(s,end=" ")
        if self.flg==1:
            self.conn[s]=self.temp
            #print("!!!!",self.temp)
            

        for i in self.lp:
            if self.vis[i]==0:
                self.tree_edge.append((s,i))
                
                self.dfs(i)
                

            elif (s,i) not in self.tree_edge and (i,s) not in self.tree_edge and (i,s) not in self.back_edge :
                self.back_edge.append((s,i))
        self.finish[s]=self.time
        self.time=self.time+1

    def timing(self):
        print("\n")
        l=[0,1,2,3,4,5]
        st=list(zip(l,self.start))
        print("Starting time-stamp are:")
        for i in st:
            print(i,end=" ")

        print("\n")
        ft=list(zip(l,self.finish))
        print("Finishing time-stamp are:")
        for j in (ft):
            print(j,end=" ")
        print("\n")
        print("Tree edges are:")
        print("\n")
        print(self.tree_edge)
        print("Back edges are:")
        print(self.back_edge)
        print("Bridge edges are:")
        print(self.bridge_edge)

    
    
    def bridge(self,s):
        self.visi[s]=1
        self.low[s]=self.ti
        self.dis[s]=self.ti
        self.ti=self.ti+1
        self.ls=self.list[s]
        for i in self.ls:
            if self.visi[i]==0:
                
                self.parent[i]=s
                self.bridge(i)
                self.low[s]=min(self.low[s],self.low[i])
                if self.low[i]>self.dis[s]:
                    self.bridge_edge.append((s,i))
                    

            elif i!=self.parent[s]:
                self.low[s]=min(self.low[s],self.dis[i])









    def connectedcom(self):
        self.flg=1
        self.vis=[0 for i in range(len(self.list))]
        print("\n")
        self.temp=1
        for i in range(len(self.list)):
            #print("###",i)
            if self.conn[i]==0:
                self.dfs(i)
                #print("&&&&",self.temp)
                #print("****",self.conn[i])
                self.temp=self.temp+1

            

        for i in range(len(self.conn)):
            print(self.conn[i],end=" ")
        print("\n")





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
    print("BFS of the given graph is:")
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
    g.bridge(s)
    g.timing()
    print("\n")
    print("The connected component matrix of the graph is:")
    g.connectedcom()
    if(g.bipartite_dfs(0)):
        print("Bipartite by dfs")
    else:
        print("Not a bipartite graph")


  
   

if __name__ == '__main__':
    main()

