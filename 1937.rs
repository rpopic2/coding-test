use std::io::{stdin, Read};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse);

    let n = input.next().unwrap();
    let mut dp = vec![vec![0usize; n]; n];
    let forest: Vec<Vec<usize>> = {
        let mut tmp = vec![Vec::with_capacity(n); n];
        for vector in &mut tmp{
            for elem in vector {
                *elem = input.next().unwrap();
            }
        }
        tmp
    };


    for col in forest {
        for elem in col {
            dp_traverse(&forest, &mut dp, n, elem, y)
        }
    }
}

impl (usize, usize) {
    fn is_valid(self, n: usize) -> bool {
        self.0 > 0 || self.0 <= n || self.1 > 0 || self.1 <= n
    }
}

fn dp_traverse(forest: &Vec<Vec<usize>>, dp: &mut Vec<Vec<usize>>, n: usize, x: usize, y: usize) -> usize {
    let cur = &dp[x][y];
    if cur != 0 {
        return cur;
    }
    
    for _ in 0..4 {
        if (x + 1, y).is_valid(n) {

        }
    }

}
