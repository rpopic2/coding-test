#alias std:scan
#alias std:array

N :: scan(usize) N =>
DP:: array(i32):new ^N + 1 =>

loop: (Cur_Day :: 0; N, DP)
    { T, P } :: { scan(i32) T =>, scan(i32) P => }

    @try_work Cur_Day + T, P;
    @try_work Cur_Day + 1, 0;
    Cur_day > N ->
        Cur_Day ++
        loop->

std:print [DP .at N] =>

@inline try_work: (Next i32, P i32, N usize, T i32, DP addr array(int), Cur_Day i32)
    Next > N -> (P, DP, Next, Cur_Day)
        [DP .at Next], [DP .at Cur_Day] + P
        max
        =[DP .at Next]
