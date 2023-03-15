use std::io::{stdin, Read};
use std::collections::HashMap;

struct DisjointMap {
    map: HashMap<String, (String, int)>
}

impl DisjointMap {
    fn new() -> DisjointMap {
        DisjointMap { map: HashMap::new().reserve(200_000) }
    }

    fn search(&self, s: &str) -> &str {
        if self.map[s].0 == s {
            return s
        }
        map 
    }
}

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace();

    let tc_count = input.next().unwrap().parse().unwrap();

    for _ in 0..tc_count {
        let inputs_count = input.next().unwrap().parse().unwrap();
        for _ in 0..inputs_count {
            let friend_a = input.next().unwrap();
            let friend_b = input.next().unwrap();
        }
    }
}
