'''
너드인가, 너드가 아닌가? 2
https://algospot.com/judge/problem/read/NERD2
@ Jae Kyun Kim
'''

class Node:
    ## Initalizing the root node
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    
    ## Insert new node with given data
    def insert(self, data):
        if self.data:
            ## Go to left
            if data < self.data: 
                if self.left is None:
                    self.left = Node(data)
                else:
                    ## Recursviely insert data
                    self.left.insert(data) 
            ## Go to right
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    ## Recursviely insert data
                    self.right.insert(data)     
        else:
            self.data = data
    
    ## Find the node with given data
    ## Return node and node's parent
    def find(self, data, parent = None):
        if data < self.data:
            ## No node found
            if self.left is None:
                return None, None
            return self.left.find(data, self)
            
        elif data > self.data:
            ## No node found
            if self.right is None:
                return None, None
            return self.right.find(data, self)
    
        else:
            return self, parent
    
    ## Count the number of children of a node
    def children_count(self):
        cnt = 0
        if self.left:
            cnt += 1
        if self.right:
            cnt += 1
        return cnt

    ## Delete the node with given data
    def delete(self, data):
        node, parent = self.find(data)
        ## Count the children
        if node is not None:
            children_count = node.children_count()

        ## Node has no children, just remove it
        if children_count == 0:
            if parent:
                if parent.left is node:
                    parent.left = None
                elif parent.right is node:
                    parent.right = None
                del node
            else:
                ## Root node
                self.data = None
        
        ## Node has one child, replace node with its child
        elif children_count == 1:
            if node.left:
                temp = node.left
            else:
                temp = node.right
            
            if parent:
                if parent.left is node:
                    parent.left = temp
                else:
                    parent.right = temp
                del node
            else:
                ## Root node
                self.left = temp.left
                self.right = temp.right
                self.data = temp.data

        ## Node has both child, find its successor
        else:
            parent = node
            successor = node.right
            ## Loop while last left successor is found
            while successor.left:
                ## Change parent
                parent = successor
                successor = successor.left
            ## Replace
            node.data = successor.data
            ## Update the node
            if parent.left == successor:
                parent.left = successor.right
            else:
                parent.right = successor.right
        
    ## Print BST
    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data)
        if self.right:
            self.right.print_tree()


if __name__=='__main__':    
    root = Node(5)
    root.insert(1)
    root.insert(3)
    root.insert(8)
    root.insert(9)
    root.insert(7)
    root.print_tree()

    print("Delete 8")
    root.delete(8)
    root.print_tree()
    print("Delete 1")
    root.delete(1)
    root.print_tree()


