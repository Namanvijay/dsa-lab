class graph:


    def __init__(self,list):
        
        self.v=len(list)
        self.vis=[0]*self.v
        self.finish=[0]*self.v
        self.start=[0]*self.v
        self.time=0
        self.list=list
        self.res={}
        self.order=[]



    def stronglyconnected(self,s):
        self.vis[s]=1
        self.start=self.time
        self.time=self.time+1
        ls=self.list[s]

        for v in ls:
            if self.vis[v]==0:
                self.stronglyconnected(v)
        self.finish[s]=self.time
        # print("$$$",s,"(((",self.finish[s])
        self.order.append(s)
        self.time=self.time+1


    def reverse(self,list):
        print("***",list)
        
        for k in list.keys():
            for val in list[k]:
                if val not in self.res.keys():
                    self.res[val]=[k]
                else:
                    self.res[val].append(k)


        print(self.res)

    def dfs_rev(self,s,lt):
        
        lt.append(s)
        self.vis[s]=1
        ls=self.res[s]
        for v in ls:
            if self.vis[v]==0:
                self.dfs_rev(v,lt)
        
        return lt


    def pullout(self):
        self.vis=[0]*self.v
        print("Strongely connected component is the graph is:")
        while(self.order):
            u=self.order.pop()
            # print("!!!")
            if self.vis[u]==0:
                lt=[]

                print(self.dfs_rev(u,lt))









        





def main():

    G = [] 
    

    file=open('input2.txt','r')
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


    li=len(G)
    lis=[]

    for i in range(li):
        lis.append(i)

    Grev=dict(zip(lis,G))
    print(Grev)
    g.stronglyconnected(0)
    g.reverse(Grev)
    # print("***",g.order)
    g.pullout()


if __name__ == '__main__':
    main()