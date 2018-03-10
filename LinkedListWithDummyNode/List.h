//
//  List.h
//  LinkedListWithDummyNode
//
//  Created by Jonathan Raysor on 3/9/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef List_h
#define List_h
template <class T>
class List{
    
private:
    
    struct ListNode{
        T data;
        ListNode * next;
        ListNode * previous;
    };
    
    ListNode * dummy = new ListNode();
    
    int numNodes;
    
    void deleteAllNodes(){
        if(numNodes==0){
            delete dummy;
            return;
        }
        
        else{
            pop_back();
            deleteAllNodes();
        }
    }
    
public:
    List(){
        dummy -> next = nullptr;
        dummy -> previous = nullptr;
        numNodes = 0;
    }
    
    ~List(){
        deleteAllNodes();
    }
    void pop_back(){
        if (dummy -> previous == nullptr)
            return;
        
        ListNode * temp = dummy -> previous -> previous;
        delete dummy -> previous;
        dummy -> previous = temp;
        
        numNodes-=1;
    }
    
    void pop_front(){
        if(dummy -> next == nullptr)
            return;
        
        ListNode * temp = dummy -> next -> next;
        delete dummy -> next;
        dummy -> next = temp;
        
        numNodes-=1;
    }
    
    void push_back(const T& value){
        numNodes++;
        ListNode * newNode = new ListNode();
        newNode -> data = value;
        newNode -> previous = dummy -> previous;
        newNode -> next = nullptr;
        
        if (dummy -> next == nullptr){
            dummy -> next = newNode;
            dummy -> previous = newNode;
        }
        
        else{
            dummy -> previous -> next = newNode;
            dummy -> previous = newNode;
        }
    }
    
    void push_front(const T& value){
        numNodes++;
        ListNode * newNode = new ListNode();
        newNode -> data = value;
        newNode -> previous = nullptr;
        newNode -> next = dummy -> next;
        
        if(dummy -> next == nullptr){
            dummy -> previous = newNode;
            dummy -> next = newNode;
        }
        
        else{
            dummy -> next = newNode;
        }
    }
    
    int size(){
        return numNodes;
    }
    
    bool empty(){
        if(numNodes==0)
            return true;
        return false;
    }
    
};


#endif /* List_h */
