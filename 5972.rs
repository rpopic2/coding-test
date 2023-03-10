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
            tmp[a].push((b, c));
            tmp[b].push((a, c));
        }
        tmp
    };

    let mut visited = vec![false; n + 1];

    let mut pq = BinaryHeap::new();
    pq.push(Reverse((1usize, 0usize)));

    while let Some(Reverse((cur_node, cur_weight))) = pq.pop() {

        if cur_node == n {
            println!("{}", cur_weight);
            break;
        }

        if visited[cur_node] {
            continue;
        }

        visited[cur_node] = true;

        for (node, weight) in &adj_list[cur_node] {
            if !visited[*node] {
                pq.push(Reverse((*node, *weight + cur_weight)));
            }
        }
    }
}
