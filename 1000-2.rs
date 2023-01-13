use std::io::{self, Read, Write};
fn main(){
    let mut buffer = [0;3];
    io::stdin()
        .read(&mut buffer)
        .unwrap();
    let i = buffer[0] - 48;
    let j = buffer[2] - 48;
    let sum = i + j;
    if sum > 9 {
    let result :[u8;2];
        result = [49, sum + 38];
    io::stdout()
        .write(&result)
        .unwrap();
    }else{
    let result :[u8;1];
        result = [sum + 48];
    io::stdout()
        .write(&result)
        .unwrap();
    }
}
