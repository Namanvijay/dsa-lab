from disjointset import *
from operator import itemgetter

class graph:


    def __init__(self,list,node):

        self.list=list
        self.node=node
        self.addedge=[]
        self.node_list=[]


        self.sorted_edge=sorted(self.list,key=itemgetter(2))
        print(self.sorted_edge)

        

    def kruskal(self):

        ds=DisjointSets()
        for i in self.node:
            node=ds.makeset(i)
            self.node_list.append(node)
        print(len(self.node_list))
        # print(str(self.node_list))
            
        
        cost=0
        for edge in self.sorted_edge:
            # print(edge)
            u=self.node_list[edge[0]]
            # print(u)
            v=self.node_list[edge[1]]
            # print(v)
            w=edge[2]
            
            if(ds.findset(u)!=ds.findset(v)):
                self.addedge.append([u,v,w])
                cost=cost+w
                ds.union(u,v)
        print("Nodes in kruskal along with their weights are:")
        for u,v,w in self.addedge:
            print(str(u),str(v),w,sep=" ")
        print("Total min cost is")
        print(cost)
        




    






def main():
    G=[]
    G1=[]
    linecount=0
    node=[]
    file=open("input4.txt","r")
    for line in file:
        first=True
        for edge in line.split(" "):
            if first==True:
                first=False
            else:
                v,weight=edge.split(",")
                G.append((linecount,int(v),int(weight)))
                G1.append((int(v),linecount,int(weight)))
        node.append(linecount)    
        linecount+=1



    print(node)
    file.close()
    print(G)
    g=graph(G,node)
    g.kruskal()
    print(G1)
   




if __name__ == '__main__':
    main()