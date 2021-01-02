#[allow(unused_imports)]
use std::cmp::*;
#[allow(unused_imports)]
use std::collections::*;

macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };

    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };

    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };

    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };

    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

const INF: i64 = 10_000_000_000;

fn main() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut p = p;
    p.sort_by(|a, b| a.cmp(b));

    let mut p_y = p.clone();
    p_y.sort_by(|a, b| a.1.cmp(&b.1));

    let mut pre = vec![-INF; n + 1];
    let mut suf = vec![-INF; n + 1];
    for i in 0..n {
        pre[i + 1] = max(pre[i], p_y[i].0 - p_y[i].1);
        suf[i + 1] = max(suf[i], p_y[n - 1 - i].0 + p_y[n - 1 - i].1);
    }

    let mut y_index: HashMap<i64, usize> = HashMap::new();
    for i in (0..n).rev() {
        y_index.insert(p_y[i].1, i);
    }

    let mut ans = 0;
    for i in 0..n {
        let &yi = y_index.get(&p[i].1).unwrap();
        let t = max(
            -p[i].0 + p[i].1 + pre[yi],
            -p[i].0 - p[i].1 + suf[n - 1 - yi],
        );
        // dbg!(yi, t);
        ans = max(ans, t);
    }
    println!("{}", ans);
}
