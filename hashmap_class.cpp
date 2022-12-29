#include <iostream>
using namespace std;

template <typename V>
class MapNode{
    public:

        string key;
        V value;
        MapNode<V> *next;
        MapNode(string key,V value){
            this->key=key;
            this->value=value;
            this->next=NULL;
        }
        ~MapNode(){
            delete this->next;
        }
};

template <typename V>
class ourmap{
    private:
        MapNode<V> **buckets;
        int count_of_nodes;
        int number_of_buckets;
    public:
        ourmap(){
            this->count_of_nodes=0;
            this->number_of_buckets=5;
            this->buckets=new MapNode<V>*[number_of_buckets];
            for(int i=0;i<number_of_buckets;i++){
                this->buckets[i]=NULL;
            }
        }
        ~ourmap(){
            for(int i=0;i<number_of_buckets;i++){
                delete this->buckets[i];
            }
            delete []this->buckets;
        }
        int size(){
            return count;
        }
    private:
        int getBucketIndex(string key){
            int hash_code=0;
            int current_coefficient=1;
            for(int i=key.size()-1;i>=0;i--){
                hash_code+=(key[i]*current_coefficient);
                hash_code=hash_code%(number_of_buckets);
                current_coefficient*=37;
                current_coefficient=current_coefficient%(number_of_buckets);
            }
            return hash_code%(number_of_buckets);
        }
        void rehash(){
            MapNode<V> **temp=this->buckets;
            buckets=new MapNode<V>*[2*number_of_buckets];
            for(int i=0;i<2*number_of_buckets;i++){
                buckets[i]=NULL;
            }
            int oldBucketCount=number_of_buckets;
            this->number_of_buckets=number_of_buckets*2;
            this->count_of_nodes=0;
            for(int i=0;i<oldBucketCount;i++){
                MapNode<V> *head=temp[i];
                while(head!=NULL){
                    string key=head->key;
                    V value=this->value;
                    insert(key,value);
                    head=head->next;
                }
            }
            for(int i=0;i<oldBucketCount;i++){
                delete temp[i];
            }
            delete []temp;
        }
    public:
        void insert(string key,V value){
            int bucket_index=getBucketIndex(key);
            MapNode<V> *head=buckets[bucket_index];
            while(head!=NULL){
                if(head->key==key){
                    head->value=value;
                    return;
                }
                head=head->next;
            }
            head=buckets[bucket_index];
            MapNode<V> *node=new MapNode<V>(key,value);
            node->next=head;
            buckets[bucket_index]=node;
            count_of_nodes++;

            double loadFactor=(double)count_of_nodes/(number_of_buckets);
            if(loadFactor>0.7){
                rehash();
            }
        }

        V remove(string key){
            int bucket_index=getBucketIndex(key);
            MapNode<V> *head=buckets[bucket_index];
            MapNode<V> *previous=NULL;
            while(head!=NULL){
                if(head->key==key){
                    if(previous==NULL){
                        buckets[bucket_index]=head->next;
                    }
                    else{
                        previous->next=head->next;
                    }
                    int answer=head->value;
                    head->next=NULL;
                    delete head;
                    count_of_nodes--;
                    return answer;
                }
                previous=head;
                head=head->next;
            }
        }
        return 0;

        V getValue(string key){
            int bucket_index=getBucketIndex(key);
            MapNode<V> *head=buckets[bucket_index];
            while(head!=NULL){
                if(head->key==key){
                    return head->value;
                }
                head=head->next;
            }
            return 0;
        }
};