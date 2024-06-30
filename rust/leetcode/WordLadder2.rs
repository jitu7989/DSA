use std::cell::RefCell;
use std::collections::{HashMap, HashSet,  VecDeque};
use std::rc::Rc;

struct Solution;
fn check_same(p0: &[u8], p1: &[u8]) -> bool {
    let mut diff = 0;
    for i in 0..p0.len() {
        if p0[i] != p1[i] {
            diff += 1;
        }
        if diff > 1 { break; }
    }
    return diff == 1;
}
impl Solution {
pub fn find_ladders(begin_word: String, end_word: String, word_list: Vec<String>) -> Vec<Vec<String>> {


    let mut paths: Vec<Vec<u16>> = vec![Vec::new(); word_list.len()];
    let mut visted = vec![false; word_list.len()];
    let mut bytes = Vec::with_capacity(word_list.len());
    let mut end = usize::MAX;

    let mut q: VecDeque<u16> = VecDeque::new();

    let mut levels = HashMap::new();
    let mut level = 0;



    levels.insert(level,Box::new(Rc::new(RefCell::new(HashSet::new()))));
    if let Some(v) = levels.get(&level) {
        v.borrow_mut().insert(word_list.len() as u16);
    }
    level+=1;
    levels.insert(level,Box::new(Rc::new(RefCell::new(HashSet::new()))));
    let mut contains = false;

    let mut idx = 0;
    for x in word_list.iter() {

        let x = x.as_bytes();
        if end_word.eq(&word_list[idx]) {
            end = idx;
        }

        if check_same(&x, &begin_word.as_bytes()) {
            q.push_back(idx as u16);
            if idx==end {
                contains=true;
            }
            if let Some(v) = levels.get(&level) {
                v.borrow_mut().insert(idx as u16);
            }

            visted[idx] = true;
        }
        bytes.push(x);
        idx += 1;
    }

    if end == usize::MAX || q.is_empty() {
        return Vec::new();
    }


    for i in 0..word_list.len() {
        for j in (i + 1)..word_list.len() {
            if i != j && check_same(&bytes[i], &bytes[j]) {
                paths[i].push(j as u16);
                paths[j].push(i as u16);
            }
        }
    }
    level+=1;
    'inner: while !q.is_empty() && !contains {

        let len = q.len();
        let vis = Box::new(Rc::new(RefCell::new(HashSet::new())));

        for _ in 0..len {
            if let Some(remove) = q.pop_front() {
                println!("{remove}");
                let elements = &paths[remove as usize];
                for idx in elements.iter() {
                    if *idx as usize==end {
                        let vis = Box::new(Rc::new(RefCell::new(HashSet::new())));
                        vis.borrow_mut().insert(*idx);
                        level+=1;
                        break 'inner;
                    }
                    if !visted[*idx as usize]  {
                        vis.borrow_mut().insert(*idx);
                    }
                }
            }
        }
        for x in vis.borrow().iter() {
            q.push_back(*x);
            visted[*x as usize] = true;
        }
        levels.insert(level,vis);
        level+=1;

    }
    level-=1;
    drop(q);
    // println!("{:?},{level},{contains}",levels);
    return dfs(&levels,&bytes,level,&word_list,&begin_word,end);
}


}
fn dfs(levels: &HashMap<i32, Box<Rc<RefCell<HashSet<u16>>>>>,
       bytes: &Vec<&[u8]>,
       level: i32,
       word_list: &Vec<String>,
       begin: &String,
       current: usize) -> Vec<Vec<String>> {

    if level==1 {
        return vec![vec![String::from(begin.as_str()),String::from(&(*word_list)[current]) ]];
    }

    let mut ans = Vec::new();
    if let Some(elements) = levels.get(&(level-1) ) {
        let elements = elements.borrow();
        for i in elements.iter() {
            if check_same((*bytes)[current],(*bytes)[*i as usize]) {
                let vec = dfs(levels, bytes, level-1, word_list, begin, *i as usize);
                for x in vec {
                    let mut x = x;
                    if let Some(el) = word_list.get(current){
                        x.push(String::from(el));
                    }
                    ans.push(x);
                }
            }
        }
    }
    return ans;
}
