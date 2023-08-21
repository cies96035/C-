
            num |= (cnt[i] & 1) << (i);
        }
        rep(i, 0, 26){
            if(num & (1 << i))continue;
            ans += scnt[i][((1 << 26) - 1) ^ num ^ (1 << i)];
        }
        rep(i, 0, 26){
            if(cnt[i] == 0){
                scnt[i][num]++;
            }
        }