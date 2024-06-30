use std::cmp::max;
use std::collections::HashMap;

fn diff(i: i32, j: i32) -> i64 {
    return i as i64 - j as i64;
}
struct Solution;
impl Solution {
    pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {

        if nums.len()<=2 {
            return 0;
        }

        let mut ans = 0;
        let mut rel:Vec<HashMap<i64,Vec<usize>>> = vec![HashMap::new();nums.len()];
        let mut zero_map = HashMap::new();

        for i in 0..nums.len() {
            let nums_i = nums[i];


            zero_map.insert(nums_i,zero_map.get(&nums_i).unwrap_or_else(|| &0)+1);
            for j in (i+1)..nums.len() {

                let nums_j = nums[j];
                let diff = diff(nums_i,nums_j);

                if diff == 0 {
                    continue;
                }

                if let Some(relations) = rel.get_mut(i) {
                    let x = relations.get_mut(&diff);
                    match x {
                        Some(x) => {
                            x.push(j);
                        },
                        None => {
                            relations.insert(diff,vec![j]);
                        }
                    }
                }

            }
        }
        let rel = rel;
        for i in 0..nums.len() {

            let nums_i = nums[i];
            for j in (i+1)..nums.len() {

                let nums_j = nums[j];
                let diff = diff(nums_i,nums_j);

                ans += dfs(&j,&diff,&rel);

            }
        }
        let mut factorial = [1u128;1000];
        let mut imax = 1;
        for (_k,v) in zero_map {
            for j in (imax+1)..=v {
                factorial[j as usize] = j*factorial[j as usize-1];
            }
            imax = max(v,imax);

            for i in 3..=v {
                ans += (factorial[v as usize]/ (factorial[i as usize]*factorial[v as usize -i as usize])) as usize;
            }
        }

        return ans as i32;
    }
}

fn dfs(current: &usize, diff: &i64, rel: &Vec<HashMap<i64, Vec<usize>>>) -> usize {
    let mut ans = 0;
    if let Some(relations_map) = rel.get(*current){
        if let Some(relations) = relations_map.get(diff) {
            for x in relations.iter() {
                ans+=1;
                ans+=dfs(x,diff,rel);
            }
        }
    }
    return ans;
}