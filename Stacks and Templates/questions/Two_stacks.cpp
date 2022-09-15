class TwoStack{
    private:
        int *arr;
        int size;
        int top1;
        int top2;
    public:
        TwoStack(int s) {
            this->size = s;
            int top1 = -1;
            int top2 = s;
            arr = new int[s];
        }

        // Push in stack 1.
        void push1(int num) {
            //atleast a empty space present
            if(top2-top1>1){
                arr[top1] = num;
                top1++;
            }
        }

         // Push in stack 2.
        void push2(int num) {
            if(top2-top1>1){
                arr[top2] = num;
                top2--;
            }   
        }

        // Pop from stack 1 and return popped element.
        int pop1() {    
            if(top1>=0){
                int ans = arr[top1];
                top1++;
                return ans;
            }
            else 
                return -1;
        }

         // Pop from stack 2 and return popped element.
        int pop2() {
            if(top2<size){
                int ans = arr[top2];
                top2--;
                return ans;
            }
            else
                return -1;
        }
};