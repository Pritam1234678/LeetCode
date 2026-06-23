class Solution {
    public String mapWordWeights(String[] words, int[] weights) {

        char result [] = new char[words.length];

        int counter = 0;

        for (String word: words){

            char c []= word.toCharArray();
            int sum =0;
            for (int i= 0;i<c.length;i++){

                sum+=weights[c[i]-'a'];
            }
            sum%=26;
            result[counter]=(char)('z'-sum);
            counter++;
            

            
        }
        return new String(result);
    }
}
