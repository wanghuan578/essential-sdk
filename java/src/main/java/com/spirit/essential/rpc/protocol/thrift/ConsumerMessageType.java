/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.spirit.essential.rpc.protocol.thrift;


import java.util.Map;
import java.util.HashMap;
import org.apache.thrift.TEnum;

public enum ConsumerMessageType implements org.apache.thrift.TEnum {
  MT_SERVICE_LIST_REQ(1100),
  MT_SERVICE_LIST_RES(1101),
  MT_SERVICE_LIST_SYNC_NOTIFY(1102),
  MT_SERVICE_LIST_SYNC_RES(1103);

  private final int value;

  private ConsumerMessageType(int value) {
    this.value = value;
  }

  /**
   * Get the integer value of this enum value, as defined in the Thrift IDL.
   */
  public int getValue() {
    return value;
  }

  /**
   * Find a the enum type by its integer value, as defined in the Thrift IDL.
   * @return null if the value is not found.
   */
  public static ConsumerMessageType findByValue(int value) { 
    switch (value) {
      case 1100:
        return MT_SERVICE_LIST_REQ;
      case 1101:
        return MT_SERVICE_LIST_RES;
      case 1102:
        return MT_SERVICE_LIST_SYNC_NOTIFY;
      case 1103:
        return MT_SERVICE_LIST_SYNC_RES;
      default:
        return null;
    }
  }
}
