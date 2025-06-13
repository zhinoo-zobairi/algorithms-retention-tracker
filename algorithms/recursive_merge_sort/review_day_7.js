const { merge } = require('../merge/review_day_7');
console.log("merge() function imported");


function recursive_merge_sort(items, l, h) {
    if (l < h) {
        const m = Math.floor((l + h) / 2);
        recursive_merge_sort(items, l, m);
        recursive_merge_sort(items, m + 1, h);
        merge(items, l, m, h);

    }
}