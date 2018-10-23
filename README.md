node-macos-progress
======
> A node package for update file progress on macOS

[![NPM](https://nodei.co/npm/macos-progress.png)](https://www.npmjs.com/package/macos-progress)

## Example

```javascript
const macProgress = require('macos-progress');
const p = new macProgress.FileProgress('/Users/wsy/Downloads/text.txt', 100);
let current = 0;
const flag = setInterval(() => {
  console.log('update...', p);
  current += 10;
  p.update(current);
  if (current === 100) {
    clearInterval(flag);
  }
}, 1000);

```
