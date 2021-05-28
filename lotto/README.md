# Lotto (2 points)

1. After reading,analysing and debugging code there is something fishy in this code.
      ```C
      // calculate lotto score
      int match = 0, j = 0;
      for(i=0; i<6; i++){
        for(j=0; j<6; j++){
          if(lotto[i] == submit[j]){
            match++;
          }
        }
      }
      ```
2. This code is doing duplicate checking,Example :

      Test Case:
      ```
      lotto = ABCDEFG 
      submit = BBBBBB (B is repeating as B is also in lotto)

      ```
3. than, from logic it will pass the check for `B` 6 times and give the match value == `6`. 
 
      ```C
      for(i=0; i<6; i++){
          for(j=0; j<6; j++){  
            if(lotto[i] == submit[j]){ // when i == 1 lotto[i] = B = submit[0-5]
              match++;
            }
          }
        }
      //after loop
      //match == 6
      ```
4. So we need to find the a any character in lotto , whose **randomness is always high**.

5. So after so much debugging and checking the value of `lotto` ,i found characters `#`,`!` ,maybe many more but these are enough.

6. Last but not least try values `######` and `!!!!!!` many times and you should get **flag**.