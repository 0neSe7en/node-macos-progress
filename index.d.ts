export class FileProgress {
  /**
   * @param path file path for progress
   * @param total totalUnitCount
   */
  constructor(path: string, total: number);

  /**
   * @param current completedUnitCount
   */
  update(current: number);
}
