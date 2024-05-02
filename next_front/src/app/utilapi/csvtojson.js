export default function ctoj(csv_array) {
  const len = csv_array.length;
  const map = csv_array.slice(1, len)
    .map((val) => {
      const obj = {};
      for (let i = 0; i < val.length; i++) {
        obj[csv_array[0][i]] = parseFloat(val[i]);
      }
      return obj;
    });
  return map;
}
