#include<iostream>
#include<limits>
class Queue{
    private:
        int rear;
        int front;
        int size =  3;
        int* arr = new int[size];
        int count;
    public:
    //construcor to initialize the queue
        Queue(){
            rear = -1;
            front = -1;
            for(int i=0;i<size;i++){
                arr[i] = 0;
            }
            count = 0;
        }
        //destructor to deallocate the memory
        ~Queue(){
            delete[] arr;
        }
        //check to if queue is empty
        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            return false;
        }
        //check is queue is full
        bool isFull(){
            if(rear == (size - 1)){
                return true;
            }
            return false;
        }
        //add a value to the queue
        void enqueue(int value){
            if(isFull()){
                std::cout<< "The queue is full"<<std::endl;
                return;
            }
            else if(isEmpty()){
                rear = 0;
                front = 0;
            }
            else{
                rear++;
            }
            arr[rear] = value;
            count++;
        }
        //remove a value from the queue
        int dequeue(){
            int temp = 0;
            if(isEmpty()){
                std::cout<< "The queue is empty"<<std::endl;
                return -1;
            }
            else if(rear == front){
                temp = arr[front];
                arr[front] = 0;
                rear = -1;
                front = -1;
            }
            else{
                temp = arr[front];
                arr[front] = 0;
                front++;
            }
            count--;
            return temp;
        }
        //return the size of the queue
        int Count(){
            return count;
        }
        //display the queue
        void display(){
            std::cout<< "Queue: ";
            for(int i=front ;i<=rear;i++){
                std::cout<< arr[i] << "\t";
            }
            std::cout<< std::endl;
        }
        //increase the queue size by doubling the previous size
        void resize(){
            int newSize = size * 2;
            int* newArray = new int[newSize];
            for(int i=0;i<size;i++){
                newArray[i] = arr[i];    
            }
            for(int i=size;i<newSize;i++){
                newArray[i] = 0;
            }
            delete[] arr;
            arr = newArray;
            size = newSize;
        }
        //display the value in front 
        int peekFront(){
            return arr[front];
        }
        //display the value in rear size of the queue
        int peekRear(){
            return arr[rear];
        }
        //reverse the order of teh elements in the queue
        void reverseOrder(){
            int temp;
            int r =  rear;
            int f=front;
            int k = rear - front + 1;
            for(int i=0;i<=k/2;i++){
                temp = arr[f];
                arr[f] = arr[r];
                arr[r] = temp;
                r--;
                f++;
            }
        }
};
//reverse a queue using temporary queues (can be used for smaller sized queues)
void reverseQueue(Queue* q1) {
    Queue* q2 = new Queue;
    Queue* q3 = new Queue;
    int size = q1->Count();
    int count =0 ;
    int temp = 0;
    while(count!=size){
        for(int i=1;i<size;i++){
            q2->enqueue(q1->dequeue());
        }
        temp = q1->dequeue();
        q3->enqueue(temp);
        q1->enqueue(temp);
        while(!q2->isEmpty()){
            q1->enqueue(q2->dequeue());
        }
        count++;
    }
    while(!q1->isEmpty()){
        q1->dequeue();
    }
    while(!q3->isEmpty()){
        q1->enqueue(q3->dequeue());
    }
    delete q2;
    delete q3;
}
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Invalid input! Please try again"<<std::endl;
        }
        else{
            return num;
        }
    }
}
int main(){
    Queue q1;
    int op,value;
    bool leave = false;
    while(leave != true){
        std::cout<< "####################operations################"<<std::endl;
        std::cout<< "1.Is the queue empty?\n2.Is the queue full?\n3.Enqueue a value to the queue\n4.Dequeue a value from the queue\n5.Display the numbere of elements in the queue\n6.Display the queue\n7.Resize the queue\n8.Display front value of the queue\n9.Display rear value of the queue\n10.Reverse the order of the queue\n11.Reverse the order of the queue using temp Queues\n12.Exit"<<std::endl;
        op = valid(op);
        while(op>12 || op<1){
            std::cout<< "Invalid number of opeartion! please try again"<<std::endl;
            op = valid(op);
        }
        switch(op){
            case 1:
                std::cout<< "Is the queue empty? "<<q1.isEmpty()<<std::endl;
                break;
            case 2:
                std::cout<< "Is the queue full? "<<q1.isFull()<<std::endl;
                break;
            case 3:
                std::cout<< "Enter the value your want to add to queue"<<std::endl;
                value  = valid(value);
                q1.enqueue(value);
                break;
            case 4:
                value = q1.dequeue();
                if(value != -1){
                    std::cout<< "You have dequeued the value "<<q1.dequeue()<<std::endl;
                }
                break;
            case 5:
                std::cout<<"The numebr of elements in the queue is "<<q1.Count()<<std::endl;
                break;
            case 6:
                q1.display();
                break;
            case 7:
                q1.resize();
                break;
            case 8:
                if(q1.isEmpty()){
                    std::cout<< "the queue is empty"<<std::endl;
                }
                else{
                    std::cout<< "You have peeked for the value "<<q1.peekFront()<< " stored at the front position."<<std::endl; 
                }
                break;
            case 9:
                if(q1.isEmpty()){
                    std::cout<< "The queue is empty"<<std::endl;
                }
                else{
                    std::cout<< "You have peeked for the value "<<q1.peekRear()<< " stored at the rear position."<<std::endl; 
                }
                break;
            case 10:
                q1.reverseOrder();
                std::cout<< "You have revresed the order of the queue"<<std::endl;
                break;
            case 11:
                reverseQueue(&q1);
                std::cout<< "You have reversed the queue using temp queues"<<std::endl;
                break;
            case 12:
                leave = true;
                std::cout<< "Bye!"<<std::endl;
                break;
        }
    }
    return 0;
}
