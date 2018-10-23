node-macos-progress
======
> A node package for update file progress on macOS

## Example

```javascript
const macProgress = require('macProgress');
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
