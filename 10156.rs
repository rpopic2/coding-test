use std::io::stdin;

fn main()
{
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse);

    let k: i32 = input.next().unwrap();
    let n = input.next().unwrap();
    let m = input.next().unwrap();

    let money_diff = k * n - m;
    if money_diff <= 0 {
        println!("0");
    }
    else {
        println!("{}", money_diff);
    }
}
