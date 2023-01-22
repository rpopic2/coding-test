fn main() {
    let mut input = String::new();
    let n = {
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().parse().unwrap()
    };

    let mut fibonacci_arr = vec![0u128; n + 1];
    fibonacci_arr[0] = 0;
    fibonacci_arr[1] = 1;
    for i in 2..=n {
        fibonacci_arr[i] = fibonacci_arr[i - 1] + fibonacci_arr[i - 2];
    }

    println!("{}", fibonacci_arr[n]);
}
