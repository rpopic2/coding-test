use std::fmt::Write;
use std::io::{stdin, Read};

const GRASS: char = '.';

fn main() {
    let mut _raw_input = String::new();
    let mut toks = {
        stdin().read_to_string(&mut _raw_input).unwrap();
        _raw_input.split_ascii_whitespace()
    };
    let tc_cnt = toks.next().unwrap().parse().unwrap();

    let mut buf = String::new();
    for _ in 0..tc_cnt {
        let mut flock_count = 0;
        let [h, w]: [usize; 2] = [0; 2].map(|_| toks.next().unwrap().parse().unwrap());
        let mut matrix: Vec<Vec<char>> = Vec::with_capacity(h);
        for _ in 0..h {
            let vector = toks.next().unwrap().chars().collect();
            matrix.push(vector);
        }
        for i in 0..h {
            for j in 0..w {
                if matrix[i][j] == GRASS {
                    continue;
                }
                flock_count += 1;
                remove_flocks(&mut matrix, (i, j), (h, w));
            }
        }
        writeln!(buf, "{}", flock_count).unwrap();
    }
    print!("{}", buf);
}

fn remove_flocks(matrix: &mut Vec<Vec<char>>, (x, y): (usize, usize), (h, w): (usize, usize)) {
    let get_adjacent = |x: usize, y: usize| {
        let mut adjacents = vec![];
        if x > 0 {
            adjacents.push((x - 1, y));
        }
        if y > 0 {
            adjacents.push((x, y - 1));
        }
        if x < h - 1 {
            adjacents.push((x + 1, y));
        }
        if y < w - 1 {
            adjacents.push((x, y + 1));
        }
        adjacents
    };

    let mut stack: Vec<(usize, usize)> = vec![];
    stack.push((x, y));

    while !stack.is_empty() {
        let (x, y) = stack.pop().unwrap();
        matrix[x][y] = GRASS;
        for vertex @ (dx, dy) in get_adjacent(x, y) {
            if matrix[dx][dy] == GRASS {
                continue;
            }
            stack.push(vertex);
        }
    }
}
