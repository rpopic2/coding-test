use std::io::{stdin, Read};
const MAX_MIN: i32 = 60;
const MAX_HOUR: i32 = 24;

fn main() {
    let mut input = String::new();
    let mut tok = {
        stdin().read_to_string(&mut input).unwrap();
        input.split_ascii_whitespace().flat_map(str::parse::<i32>)
    };
    let hour = tok.next().unwrap();
    let min = tok.next().unwrap();
    let cook_time = tok.next().unwrap();

    let mut min = min + cook_time;
    let carry = min >= MAX_MIN;
    let mut overflow = 0;
    if carry {
        overflow = min / MAX_MIN;
        min = min % MAX_MIN;
    };
    let mut hour = hour + overflow;
    if hour >= MAX_HOUR {
        hour = hour % MAX_HOUR;
    }
    println!("{} {}", hour, min);
}
