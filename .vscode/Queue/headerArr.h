

class Queue{
    int cs;
    int ms;
    int *arr;
    int front;
    int rear;

    public:

    Queue(int default_size = 5){
        cs = 0;
        ms = default_size;

        arr = new int[ms];

        front = 0;
        rear = ms - 1;
    }
    
    bool full(){
        return cs == ms;
    }

    bool empty(){
        return cs == 0;
    }

    void push(int data){
        if(!full()){
            //take the rear to the next step
            rear = (rear+1)%ms;
            arr[rear] = data;
            cs++;
        }
    }

    void pop(){
        if(!empty()){
            front = (front+1)%ms;
            cs--;
            return;
        }
    }

    int getfront(){
        return arr[front];
    }
};