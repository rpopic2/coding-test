use std::io::stdin;
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: usize = input.split_ascii_whitespace().map(str::parse).flatten().next().unwrap();
    let mut dp: Vec<i64> = vec![0, 1];
    for i in 2..=n {
        dp.push(dp[i - 1] + dp[i - 2]);
    }
    println!("{}", dp[n]);
}

