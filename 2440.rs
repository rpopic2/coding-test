use std::io::stdin;
fn main(){
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    let n: u8 = s.trim().parse().unwrap();

    let mut buf = String::new();
    for i in (1..=n).rev(){
        for _ in 0..i {
            buf.push('*');
        }
        buf.push('\n');
    }
    println!("{buf}");
}
