#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED


#include <vector>
#include <algorithm>
#include "Movie.h"
#include <string>
#include <string>
using namespace std;
template <typename KeyType, typename ValueType>
class TreeMultimap
{
    private:
      struct Node//creating node struct to run our list
        {
          Node(const KeyType& key,const ValueType& value){
              m_key=key;
              m_value.push_back(value);
              left=right=nullptr;
          }
          KeyType m_key;
          std::vector<ValueType> m_value;
          Node* left;
          Node* right;
          
      };
      Node* head;
      void FreeTree(Node* cur)//Free Tree Algo from carey's slides
      {
          if (cur==nullptr)
              return;
          FreeTree(cur->left);
          FreeTree(cur->right);
          delete cur;
      }

  public:
    class Iterator
    {
        private:
      typename std::vector<ValueType>::iterator it;
        typename std::vector<ValueType>::iterator pt;
      bool valid=false;
        
      public:
//        void setValid(bool a){
//            valid=a;
//        }
        Iterator()
        {
        }
        Iterator(Node *p)//setting iterator up and instantiating start and end values
        {
            it=p->m_value.begin();
            valid=true;
            pt=p->m_value.end();
        }
        ValueType& get_value() const
        {
            return *it;
            //throw 1;  // Replace this line with correct code.
        }
        bool is_valid() const
        {
            if(get_value()==NULL||it==pt)
                return false;
            else return true;
//            return valid;  // Replace this line with correct code.
        }

        void advance()
        {
           
            it++;// Replace this line with correct code.
//            if(is_valid())
//                return;
        }
    };

    TreeMultimap()
    {
        
        head=nullptr;
        // doesn't point to any value
        
//        if (!it.is_valid())
//            std::cout << "This will print!\n";
    }
    ~TreeMultimap()
    {
        FreeTree(head);
        // Replace this line with correct code.
    }

    void insert(const KeyType& key, const ValueType& value)//making BST
    {
        //Node *p=head;
        if(head==nullptr)
        {
            head=new Node(key,value);
            return;
        }
        Node *p=head;
        for(;;){
            if(key==p->m_key)
            {
                p->m_value.push_back(value);
                return;
            }
            if(key<p->m_key)
            {
                if(p->left!=nullptr)
                    p=p->left;
                else
                {
                    p->left=new Node(key,value);
                    return;
                }
            }
            else if(key>p->m_key)
            {
                if(p->right!=nullptr)
                    p=p->right;
                else
                {
                    p->right=new Node(key,value);
                    return;
                }
            }
        }
        // Replace this line with correct code.
    }
    Iterator find(const KeyType& key) const//finding values in BST
    {
        Node* p=head;
        while(p!=nullptr)
        {
            if(key==p->m_key)
            {
                return Iterator(p);
            }
            else if (key>p->m_key)
                p=p->right;
            else if (key<p->m_key)
                p=p->left;
        }
        return nullptr;  // Replace this line with correct code.
    }
};

#endif // TREEMULTIMAP_INCLUDED

