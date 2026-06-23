class Solution {
    static final long MOD = 1_000_000_007L;
    static final long INV2 = 500000004L;

    public int maxTotalValue(int[] value, int[] decay, int m) {
        long positiveCount = 0;

        for (int i = 0; i < value.length; i++) {
            positiveCount += (value[i] - 1L) / decay[i] + 1L;
            if (positiveCount > m) {
                positiveCount = m;
                break;
            }
        }

        long k = Math.min((long) m, positiveCount);
        if (k == 0) return 0;

        long lo = 1, hi = 1_000_000_000L;

        while (lo < hi) {
            long mid = (lo + hi + 1) >>> 1;

            if (countAtLeast(value, decay, mid) >= k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        long threshold = lo;

        long cntGreater = 0;
        long ans = 0;

        for (int i = 0; i < value.length; i++) {
            long a = value[i];
            long d = decay[i];

            if (a < threshold + 1) continue;

            long c = (a - (threshold + 1)) / d + 1;

            cntGreater += c;

            long cMod = c % MOD;
            long first = a % MOD;
            long last = (a - (c - 1) * d) % MOD;

            long seqSum = cMod * ((first + last) % MOD) % MOD;
            seqSum = seqSum * INV2 % MOD;

            ans = (ans + seqSum) % MOD;
        }

        long remaining = k - cntGreater;
        ans = (ans + (remaining % MOD) * (threshold % MOD)) % MOD;

        return (int) ans;
    }

    private long countAtLeast(int[] value, int[] decay, long x) {
        long count = 0;

        for (int i = 0; i < value.length; i++) {
            long a = value[i];
            long d = decay[i];

            if (a >= x) {
                count += (a - x) / d + 1;
            }
        }

        return count;
    }
}
