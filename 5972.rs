use std::cmp::Reverse;
use std::io::{stdin, Read};
use std::collections::BinaryHeap;

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let m = input.next().unwrap();

    let adj_list: Vec<Vec<(usize, usize)>> = {
        let mut tmp = vec![Vec::new(); n + 1];
        for _ in 0..m {
            let a = input.next().unwrap();
            let b = input.next().unwrap();
            let c = input.next().unwrap();
            tmp[a].push((c, b));
            tmp[b].push((c, a));
        }
        tmp
    };

    let mut visited = vec![false; n + 1];

    let mut pq = BinaryHeap::new();
    pq.push(Reverse((0usize, 1usize)));

    while let Some(Reverse((cur_weight, cur_node))) = pq.pop() {

        if cur_node == n {
            println!("{}", cur_weight);
            return;
        }

        if visited[cur_node] {
            continue;
        }

        visited[cur_node] = true;

        for (weight, node) in adj_list[cur_node].iter() {
            if !visited[*node] {
                pq.push(Reverse((*weight + cur_weight, *node)));
            }
        }
    }
}
