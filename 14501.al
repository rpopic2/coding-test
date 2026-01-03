[N] ::
    [std:Cin] .>> N => =[]

N :: [N] =
$ = N + 1
$ lsr 61 is nonzero exception->
$ is zero panic

Size :: $ * #sizeof i32
DP :: std:heap:alloc Size bytes=> =
&DP.Size :: DP
&DP.Start :: DP + #sizeof i32
DP.End :: DP + Size

0 =[DP.Size]
N is zero ->
    c:memset DP.Start, 0, DP.End - #sizeof int=>

Cin :: [std:Cin]
Cur_Day :: 0

$[N]
::
    [T], [P] ::
        Cin .>> T   | Cin .>> P
        =[]         | =[]
    $N, $Next ::= [T] + Cur_Day
    < ->
        ([DP, i32 Cur_Day], [P] +), [DP, i32 $Next]
        max
        =[DP, i32 $Next]

    $N, $Next = Cur_Day + 1 
    < ->
        $Offset = DP + i32 Cur_Day
        Cur_Day = $Next
        A, B :: [DP + Cur_Day, {i32, i32}]
        max
        =[DP + $Offset]
        loop->

std:Cout .<< [DP + i32 $N] =>
ret 0

