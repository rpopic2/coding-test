use std::io;
fn main(){
    let stdin = io::stdin();
    let mut jh = String::new();
    let mut doctor = String::new();

    stdin.read_line(&mut jh).unwrap();
    stdin.read_line(&mut doctor).unwrap();

    let jhlen = jh.len();
    let doclen = doctor.len();

    let r = if jhlen >= doclen {"go"} else {"no"};
    println!("{}", r);

}
