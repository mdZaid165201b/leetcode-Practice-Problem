/*Not Exactly Fulfill the requirements of leetcode*/

/*
  Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1],
  then return 0.

  Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


*/



    int reverse(int x) {
        int count = 0;
        if(x < 0){
            int temp = x * -1;
            while(temp){
                count++;
                temp /= 10;
            }
            int value = 0;
            int i = 0;
            temp  = x;
            while(i < count - 1){
                int rem = temp % 10;
                value += rem;
                value *= 10;
                temp = temp / 10;
                i++;
            }
            value += temp;
            return (value);
        }
        else{
            int temp = x;
            while(temp){
                count++;
                temp /= 10;
            }
            int value = 0;
            int i = 0;
            temp  = x;
            while(i < count - 1){
                int rem = temp % 10;
                value += rem;
                value *= 10;
                temp = temp / 10;
                i++;
            }
            value += temp;
            cout<<value;
            return value;
        }
    }
