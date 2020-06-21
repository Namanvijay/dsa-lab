from collections import deque
class graph:
    def __init__(self,G):
        self.list=G
        self.visited=[0 for i in range(len(self.list))]
        self.visi1=[0 for i in range(len(self.list))]
        self.ls=[]
        self.color=[-1 for i in range(len(self.list))]
        self.ad_matrix=[[0 for i in range(len(self.list))] for j in range(len(self.list))]
        self.dist=[0 for i in range(len(self.list))]
        self.visi=[0 for i in range(len(self.list))]
        self.vis=[0 for i in range(len(self.list))]
        
        
        self.start=[0 for i in range(len(self.list))]
        self.finish=[0 for i in range(len(self.list))]
        self.time=0
        self.low=[0 for i in range(len(self.list))]
        self.dis=[0 for i in range(len(self.list))]
        self.parent=[0 for i in range(len(self.list))]
        self.ti=0
        
        
        self.flag=0
       
        

        self.temp=0
        self.tree_edge=[]
        self.back_edge=[] 
        self.forward_edge=[]
        self.cross_edge=[] 

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


    def dfs(self,s):
    	self.visited[s]=1
    	self.start[s]=self.time
    	self.time=self.time+1

    	print(s,end=" ")
    	self.ls=self.list[s]
    	for i in (self.ls):
    		if self.visited[i]==0:
    			
    			self.dfs(i)
  

    	self.finish[s]=self.time
    	self.time=self.time+1


    def dfs_iter(self,s):
        
        stack=[]
        stack.append(s)
        while(stack):
            sp=stack[-1]
            
            stack.pop()
            if self.visi1[sp]==0:
                print(sp,end=" ")
                self.visi1[sp]=1

            
            self.ls=self.list[sp]
            for i in self.ls:
                if self.visi1[i]==0:
                    
                    stack.append(i)
                    
                    


         

    
    def bridge(self,s):
    	self.vis[s]=1
    	self.low[s]=self.ti
    	
    	self.dis[s]=self.ti
    	self.ti=self.ti+1
    	self.ls=self.list[s]
    	for i in self.ls:
    		if self.vis[i]==0:
    			self.parent[i]=s
    			self.bridge(i)
    			
    			self.low[s]=min(self.low[s],self.low[i])
    			if self.low[i]>self.dis[s]:
    				print(s,i)

    		elif i!=self.parent[s]:
    			self.low[s]=min(self.low[s],self.dis[i])





    def edges(self,s):
    	self.visi[s]=1
    	self.ls=self.list[s]
    	for i in self.ls:
    		if self.visi[i]==0:
    			self.tree_edge.append((s,i))
    			self.edges(i)
    		elif((self.start[s]<self.start[i]) and (self.start[i]<self.finish[i]) and (self.finish[i]<self.finish[s])):
    			self.forward_edge.append((s,i))

    		elif((self.start[i]<self.start[s]) and (self.finish[s]<self.finish[i])):
    			self.back_edge.append((s,i))

    		elif((self.start[i]<self.start[s]) and (self.finish[i]<self.finish[s])):
    			self.cross_edge.append((s,i))


    def cycle(self):
    	if len(self.back_edge)==0:
    		print("No cycle")
    	else:
    		print("Cyclic graph")



    def printtime(self):
    	print("\n")
    	print("Starting timestamp are:")
    	print(self.start)
    	print("Ending timestamp are:")
    	print(self.finish)
    	print("Forward edges are:")
    	print(self.forward_edge)
    	print("Tree edges are:")
    	print(self.tree_edge)
    	print("backedges edges are:")
    	print(self.back_edge)
    	print("cross edges are:")
    	print(self.cross_edge)



   


    



   
   

    

    
    
    


    

   






    




def main():
    
    G = [] 
    

    file=open('input1.txt','r')
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
    g.dfs(s)
    g.edges(s)
    g.printtime()
    g.cycle()
   # g.bridge(s)
    g.dfs_iter(s)


  

if __name__ == '__main__':
    main()

