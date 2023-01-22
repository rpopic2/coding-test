fn main() {
    let mut input = String::new();
    let n = {
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().parse().unwrap()
    };
    let mut fibonacci_arr = vec![0u128; n + 1];

    println!("{}", fibonacci(n, &mut fibonacci_arr));
}

fn fibonacci(n: usize, memo: &mut Vec<u128>) -> u128 {
    if n < 2 { return n as u128; }
    if memo[n] != 0 { return memo[n] };
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    memo[n]
}
