function countSubstrings(s: string): number {

    var count = 0;
    function expand(left: number, right: number): void {
        while (left >= 0 && right < s.length && s[left] === s[right]) {
            count++;
            right++;
            left--;
        }

    }
    for (let i = 0; i < s.length; i++) {
        expand( i, i);
        expand( i, i + 1);
    }
    return count;
};
