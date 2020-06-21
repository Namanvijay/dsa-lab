import heapq

class nodes:
    def __init__(self,index):
        self.index=index
        self.dist=100
        self.pred=-1
        self.visited=0


    def __eq__(self,other):
        return self.dist==other.dist
    def __le__(self,other):
        return self.dist<=other.dist
    def __ge__(self,other):
        return self.dist>=other.dist
    def __lt__(self,other):
        return self.dist<other.dist
    def __gt__(self,other):
        return self.dist>other.dist

def prims(G,node_list,s):
    node_list[s].dist=0
    node_list[s].visited=1

    heap_list=list(node_list)
    heapq.heapify(heap_list)
    while(len(heap_list)!=0):
        u=heapq.heappop(heap_list)
        t=u.index
        node_list[t].visited=1
        for ls in G[u.index]:
            v=ls[0]
            w=ls[1]
            if node_list[v].dist>w and node_list[v].visited==0:
                node_list[v].dist=w
                
                node_list[v].pred=u.index
                heapq.heapify(heap_list)


    print("MST is")
    cost=0
    for i in node_list:
        if i.pred!=-1:
            print((i.index,i.dist,i.pred))
            cost=cost+i.dist
    print(cost)






def main():
    ''' Adjacency List representation. G is a list of lists. '''
    G = [] 

    file=open('input5.txt','r')
    for line in file:
        line=line.strip()
        adjacentVertices = []
        first=True
        for edge in line.split(' '):
            if first:
                first=False
                continue
            node,weight = edge.split(',')
            adjacentVertices.append((int(node),int(weight)))
        G.append(adjacentVertices)

    file.close()

    print(G)
    node_list=[]
    for i in range(len(G)):
        node=nodes(i)
        node_list.append(node)
    
   
    prims(G,node_list,0)

if __name__ == '__main__':
    main()

