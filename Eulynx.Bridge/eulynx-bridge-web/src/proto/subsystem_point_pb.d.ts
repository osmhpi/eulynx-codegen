import * as jspb from 'google-protobuf'



export class Nothing extends jspb.Message {
  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Nothing.AsObject;
  static toObject(includeInstance: boolean, msg: Nothing): Nothing.AsObject;
  static serializeBinaryToWriter(message: Nothing, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Nothing;
  static deserializeBinaryFromReader(message: Nothing, reader: jspb.BinaryReader): Nothing;
}

export namespace Nothing {
  export type AsObject = {
  }
}

export class Input extends jspb.Message {
  getMovepoint(): MovePointPosition;
  setMovepoint(value: MovePointPosition): Input;
  hasMovepoint(): boolean;
  clearMovepoint(): Input;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Input.AsObject;
  static toObject(includeInstance: boolean, msg: Input): Input.AsObject;
  static serializeBinaryToWriter(message: Input, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Input;
  static deserializeBinaryFromReader(message: Input, reader: jspb.BinaryReader): Input;
}

export namespace Input {
  export type AsObject = {
    movepoint?: MovePointPosition,
  }

  export enum MovepointCase { 
    _MOVEPOINT_NOT_SET = 0,
    MOVEPOINT = 1,
  }
}

export class PrimaryData extends jspb.Message {
  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): PrimaryData.AsObject;
  static toObject(includeInstance: boolean, msg: PrimaryData): PrimaryData.AsObject;
  static serializeBinaryToWriter(message: PrimaryData, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): PrimaryData;
  static deserializeBinaryFromReader(message: PrimaryData, reader: jspb.BinaryReader): PrimaryData;
}

export namespace PrimaryData {
  export type AsObject = {
  }
}

export class PrimaryState extends jspb.Message {
  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): PrimaryState.AsObject;
  static toObject(includeInstance: boolean, msg: PrimaryState): PrimaryState.AsObject;
  static serializeBinaryToWriter(message: PrimaryState, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): PrimaryState;
  static deserializeBinaryFromReader(message: PrimaryState, reader: jspb.BinaryReader): PrimaryState;
}

export namespace PrimaryState {
  export type AsObject = {
  }
}

export class State extends jspb.Message {
  getConnection(): PrimaryState | undefined;
  setConnection(value?: PrimaryState): State;
  hasConnection(): boolean;
  clearConnection(): State;

  getPointposition(): string;
  setPointposition(value: string): State;
  hasPointposition(): boolean;
  clearPointposition(): State;

  getAbilitytomove(): string;
  setAbilitytomove(value: string): State;
  hasAbilitytomove(): boolean;
  clearAbilitytomove(): State;

  getTimeout(): boolean;
  setTimeout(value: boolean): State;
  hasTimeout(): boolean;
  clearTimeout(): State;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): State.AsObject;
  static toObject(includeInstance: boolean, msg: State): State.AsObject;
  static serializeBinaryToWriter(message: State, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): State;
  static deserializeBinaryFromReader(message: State, reader: jspb.BinaryReader): State;
}

export namespace State {
  export type AsObject = {
    connection?: PrimaryState.AsObject,
    pointposition?: string,
    abilitytomove?: string,
    timeout?: boolean,
  }

  export enum PointpositionCase { 
    _POINTPOSITION_NOT_SET = 0,
    POINTPOSITION = 2,
  }

  export enum AbilitytomoveCase { 
    _ABILITYTOMOVE_NOT_SET = 0,
    ABILITYTOMOVE = 3,
  }

  export enum TimeoutCase { 
    _TIMEOUT_NOT_SET = 0,
    TIMEOUT = 4,
  }
}

export enum MovePointPosition { 
  RIGHT = 0,
  LEFT = 1,
}
