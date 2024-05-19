export default function ctoj(csv_array) {
  const len = csv_array.length;
  const map = csv_array.slice(1, len)
    .map((val) => {
      const obj = {};
      for (let i = 0; i < val.length; i++) {
        const floatValue = parseFloat(val[i]);
        obj[csv_array[0][i]] = floatValue ? floatValue : val[i];
      }
      return obj;
    });
  return map;
}
