use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    let mut tok = {
        stdin().read_to_string(&mut input).unwrap();
        input.split_ascii_whitespace().flat_map(str::parse::<usize>)
    };
    tok.next().unwrap();
    let k = tok.next().unwrap();
    let coins: Vec<_> = tok.collect();

    let mut dp = vec![0usize; k + 1];
    dp[0] = 1;
    for coin in coins.iter() {
        for i in *coin..=k {
            dp[i] += dp[i - coin];
        }
    }
    println!("{}", dp[k]);
}
