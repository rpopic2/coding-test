#alias std:io:scan

N :: scan(usize) N =>
DP :: std:arr(i32):new ^N + 1 =>
Cur_Day :: 0

loop:
    [T] | [P] :: scan(i32) T => | P =>

    Next :: [T] + Cur_Day
    N < Next ->
        max (DP .at Cur_Day + [P]), ([DP + Next])
        =[DP + Next]

    Next = Cur_Day + 1
    N < Next ->
        Offset :: DP + i32 x Cur_Day
        Cur_Day = Next
        max ([DP .at Cur_Day, { i32, i32 }])
        =[DP + Offset]
        loop->

std:io:print [DP + i32 $N] =>
ret 0

