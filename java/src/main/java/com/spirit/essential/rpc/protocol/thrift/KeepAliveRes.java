/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.spirit.essential.rpc.protocol.thrift;

@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked", "unused"})
@javax.annotation.Generated(value = "Autogenerated by Thrift Compiler (0.10.0)", date = "2019-08-22")
public class KeepAliveRes implements org.apache.thrift.TBase<KeepAliveRes, KeepAliveRes._Fields>, java.io.Serializable, Cloneable, Comparable<KeepAliveRes> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("KeepAliveRes");

  private static final org.apache.thrift.protocol.TField ERROR_CODE_FIELD_DESC = new org.apache.thrift.protocol.TField("error_code", org.apache.thrift.protocol.TType.I32, (short)1);
  private static final org.apache.thrift.protocol.TField ERROR_TEXT_FIELD_DESC = new org.apache.thrift.protocol.TField("error_text", org.apache.thrift.protocol.TType.STRING, (short)2);
  private static final org.apache.thrift.protocol.TField ID_FIELD_DESC = new org.apache.thrift.protocol.TField("id", org.apache.thrift.protocol.TType.I32, (short)3);
  private static final org.apache.thrift.protocol.TField TIMESTAMP_BEGIN_FIELD_DESC = new org.apache.thrift.protocol.TField("timestamp_begin", org.apache.thrift.protocol.TType.I64, (short)4);
  private static final org.apache.thrift.protocol.TField TIMESTAMP_END_FIELD_DESC = new org.apache.thrift.protocol.TField("timestamp_end", org.apache.thrift.protocol.TType.I64, (short)5);

  private static final org.apache.thrift.scheme.SchemeFactory STANDARD_SCHEME_FACTORY = new KeepAliveResStandardSchemeFactory();
  private static final org.apache.thrift.scheme.SchemeFactory TUPLE_SCHEME_FACTORY = new KeepAliveResTupleSchemeFactory();

  public int error_code; // required
  public java.lang.String error_text; // required
  public int id; // required
  public long timestamp_begin; // required
  public long timestamp_end; // required

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    ERROR_CODE((short)1, "error_code"),
    ERROR_TEXT((short)2, "error_text"),
    ID((short)3, "id"),
    TIMESTAMP_BEGIN((short)4, "timestamp_begin"),
    TIMESTAMP_END((short)5, "timestamp_end");

    private static final java.util.Map<java.lang.String, _Fields> byName = new java.util.HashMap<java.lang.String, _Fields>();

    static {
      for (_Fields field : java.util.EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // ERROR_CODE
          return ERROR_CODE;
        case 2: // ERROR_TEXT
          return ERROR_TEXT;
        case 3: // ID
          return ID;
        case 4: // TIMESTAMP_BEGIN
          return TIMESTAMP_BEGIN;
        case 5: // TIMESTAMP_END
          return TIMESTAMP_END;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new java.lang.IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    public static _Fields findByName(java.lang.String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final java.lang.String _fieldName;

    _Fields(short thriftId, java.lang.String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public java.lang.String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  private static final int __ERROR_CODE_ISSET_ID = 0;
  private static final int __ID_ISSET_ID = 1;
  private static final int __TIMESTAMP_BEGIN_ISSET_ID = 2;
  private static final int __TIMESTAMP_END_ISSET_ID = 3;
  private byte __isset_bitfield = 0;
  public static final java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new java.util.EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.ERROR_CODE, new org.apache.thrift.meta_data.FieldMetaData("error_code", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.ERROR_TEXT, new org.apache.thrift.meta_data.FieldMetaData("error_text", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.ID, new org.apache.thrift.meta_data.FieldMetaData("id", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.TIMESTAMP_BEGIN, new org.apache.thrift.meta_data.FieldMetaData("timestamp_begin", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    tmpMap.put(_Fields.TIMESTAMP_END, new org.apache.thrift.meta_data.FieldMetaData("timestamp_end", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I64)));
    metaDataMap = java.util.Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(KeepAliveRes.class, metaDataMap);
  }

  public KeepAliveRes() {
  }

  public KeepAliveRes(
    int error_code,
    java.lang.String error_text,
    int id,
    long timestamp_begin,
    long timestamp_end)
  {
    this();
    this.error_code = error_code;
    setError_codeIsSet(true);
    this.error_text = error_text;
    this.id = id;
    setIdIsSet(true);
    this.timestamp_begin = timestamp_begin;
    setTimestamp_beginIsSet(true);
    this.timestamp_end = timestamp_end;
    setTimestamp_endIsSet(true);
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public KeepAliveRes(KeepAliveRes other) {
    __isset_bitfield = other.__isset_bitfield;
    this.error_code = other.error_code;
    if (other.isSetError_text()) {
      this.error_text = other.error_text;
    }
    this.id = other.id;
    this.timestamp_begin = other.timestamp_begin;
    this.timestamp_end = other.timestamp_end;
  }

  public KeepAliveRes deepCopy() {
    return new KeepAliveRes(this);
  }

  @Override
  public void clear() {
    setError_codeIsSet(false);
    this.error_code = 0;
    this.error_text = null;
    setIdIsSet(false);
    this.id = 0;
    setTimestamp_beginIsSet(false);
    this.timestamp_begin = 0;
    setTimestamp_endIsSet(false);
    this.timestamp_end = 0;
  }

  public int getError_code() {
    return this.error_code;
  }

  public KeepAliveRes setError_code(int error_code) {
    this.error_code = error_code;
    setError_codeIsSet(true);
    return this;
  }

  public void unsetError_code() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __ERROR_CODE_ISSET_ID);
  }

  /** Returns true if field error_code is set (has been assigned a value) and false otherwise */
  public boolean isSetError_code() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __ERROR_CODE_ISSET_ID);
  }

  public void setError_codeIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __ERROR_CODE_ISSET_ID, value);
  }

  public java.lang.String getError_text() {
    return this.error_text;
  }

  public KeepAliveRes setError_text(java.lang.String error_text) {
    this.error_text = error_text;
    return this;
  }

  public void unsetError_text() {
    this.error_text = null;
  }

  /** Returns true if field error_text is set (has been assigned a value) and false otherwise */
  public boolean isSetError_text() {
    return this.error_text != null;
  }

  public void setError_textIsSet(boolean value) {
    if (!value) {
      this.error_text = null;
    }
  }

  public int getId() {
    return this.id;
  }

  public KeepAliveRes setId(int id) {
    this.id = id;
    setIdIsSet(true);
    return this;
  }

  public void unsetId() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __ID_ISSET_ID);
  }

  /** Returns true if field id is set (has been assigned a value) and false otherwise */
  public boolean isSetId() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __ID_ISSET_ID);
  }

  public void setIdIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __ID_ISSET_ID, value);
  }

  public long getTimestamp_begin() {
    return this.timestamp_begin;
  }

  public KeepAliveRes setTimestamp_begin(long timestamp_begin) {
    this.timestamp_begin = timestamp_begin;
    setTimestamp_beginIsSet(true);
    return this;
  }

  public void unsetTimestamp_begin() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __TIMESTAMP_BEGIN_ISSET_ID);
  }

  /** Returns true if field timestamp_begin is set (has been assigned a value) and false otherwise */
  public boolean isSetTimestamp_begin() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __TIMESTAMP_BEGIN_ISSET_ID);
  }

  public void setTimestamp_beginIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __TIMESTAMP_BEGIN_ISSET_ID, value);
  }

  public long getTimestamp_end() {
    return this.timestamp_end;
  }

  public KeepAliveRes setTimestamp_end(long timestamp_end) {
    this.timestamp_end = timestamp_end;
    setTimestamp_endIsSet(true);
    return this;
  }

  public void unsetTimestamp_end() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __TIMESTAMP_END_ISSET_ID);
  }

  /** Returns true if field timestamp_end is set (has been assigned a value) and false otherwise */
  public boolean isSetTimestamp_end() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __TIMESTAMP_END_ISSET_ID);
  }

  public void setTimestamp_endIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __TIMESTAMP_END_ISSET_ID, value);
  }

  public void setFieldValue(_Fields field, java.lang.Object value) {
    switch (field) {
    case ERROR_CODE:
      if (value == null) {
        unsetError_code();
      } else {
        setError_code((java.lang.Integer)value);
      }
      break;

    case ERROR_TEXT:
      if (value == null) {
        unsetError_text();
      } else {
        setError_text((java.lang.String)value);
      }
      break;

    case ID:
      if (value == null) {
        unsetId();
      } else {
        setId((java.lang.Integer)value);
      }
      break;

    case TIMESTAMP_BEGIN:
      if (value == null) {
        unsetTimestamp_begin();
      } else {
        setTimestamp_begin((java.lang.Long)value);
      }
      break;

    case TIMESTAMP_END:
      if (value == null) {
        unsetTimestamp_end();
      } else {
        setTimestamp_end((java.lang.Long)value);
      }
      break;

    }
  }

  public java.lang.Object getFieldValue(_Fields field) {
    switch (field) {
    case ERROR_CODE:
      return getError_code();

    case ERROR_TEXT:
      return getError_text();

    case ID:
      return getId();

    case TIMESTAMP_BEGIN:
      return getTimestamp_begin();

    case TIMESTAMP_END:
      return getTimestamp_end();

    }
    throw new java.lang.IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new java.lang.IllegalArgumentException();
    }

    switch (field) {
    case ERROR_CODE:
      return isSetError_code();
    case ERROR_TEXT:
      return isSetError_text();
    case ID:
      return isSetId();
    case TIMESTAMP_BEGIN:
      return isSetTimestamp_begin();
    case TIMESTAMP_END:
      return isSetTimestamp_end();
    }
    throw new java.lang.IllegalStateException();
  }

  @Override
  public boolean equals(java.lang.Object that) {
    if (that == null)
      return false;
    if (that instanceof KeepAliveRes)
      return this.equals((KeepAliveRes)that);
    return false;
  }

  public boolean equals(KeepAliveRes that) {
    if (that == null)
      return false;
    if (this == that)
      return true;

    boolean this_present_error_code = true;
    boolean that_present_error_code = true;
    if (this_present_error_code || that_present_error_code) {
      if (!(this_present_error_code && that_present_error_code))
        return false;
      if (this.error_code != that.error_code)
        return false;
    }

    boolean this_present_error_text = true && this.isSetError_text();
    boolean that_present_error_text = true && that.isSetError_text();
    if (this_present_error_text || that_present_error_text) {
      if (!(this_present_error_text && that_present_error_text))
        return false;
      if (!this.error_text.equals(that.error_text))
        return false;
    }

    boolean this_present_id = true;
    boolean that_present_id = true;
    if (this_present_id || that_present_id) {
      if (!(this_present_id && that_present_id))
        return false;
      if (this.id != that.id)
        return false;
    }

    boolean this_present_timestamp_begin = true;
    boolean that_present_timestamp_begin = true;
    if (this_present_timestamp_begin || that_present_timestamp_begin) {
      if (!(this_present_timestamp_begin && that_present_timestamp_begin))
        return false;
      if (this.timestamp_begin != that.timestamp_begin)
        return false;
    }

    boolean this_present_timestamp_end = true;
    boolean that_present_timestamp_end = true;
    if (this_present_timestamp_end || that_present_timestamp_end) {
      if (!(this_present_timestamp_end && that_present_timestamp_end))
        return false;
      if (this.timestamp_end != that.timestamp_end)
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    int hashCode = 1;

    hashCode = hashCode * 8191 + error_code;

    hashCode = hashCode * 8191 + ((isSetError_text()) ? 131071 : 524287);
    if (isSetError_text())
      hashCode = hashCode * 8191 + error_text.hashCode();

    hashCode = hashCode * 8191 + id;

    hashCode = hashCode * 8191 + org.apache.thrift.TBaseHelper.hashCode(timestamp_begin);

    hashCode = hashCode * 8191 + org.apache.thrift.TBaseHelper.hashCode(timestamp_end);

    return hashCode;
  }

  @Override
  public int compareTo(KeepAliveRes other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = java.lang.Boolean.valueOf(isSetError_code()).compareTo(other.isSetError_code());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetError_code()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.error_code, other.error_code);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetError_text()).compareTo(other.isSetError_text());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetError_text()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.error_text, other.error_text);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetId()).compareTo(other.isSetId());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetId()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.id, other.id);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetTimestamp_begin()).compareTo(other.isSetTimestamp_begin());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetTimestamp_begin()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.timestamp_begin, other.timestamp_begin);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetTimestamp_end()).compareTo(other.isSetTimestamp_end());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetTimestamp_end()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.timestamp_end, other.timestamp_end);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    return 0;
  }

  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    scheme(iprot).read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    scheme(oprot).write(oprot, this);
  }

  @Override
  public java.lang.String toString() {
    java.lang.StringBuilder sb = new java.lang.StringBuilder("KeepAliveRes(");
    boolean first = true;

    sb.append("error_code:");
    sb.append(this.error_code);
    first = false;
    if (!first) sb.append(", ");
    sb.append("error_text:");
    if (this.error_text == null) {
      sb.append("null");
    } else {
      sb.append(this.error_text);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("id:");
    sb.append(this.id);
    first = false;
    if (!first) sb.append(", ");
    sb.append("timestamp_begin:");
    sb.append(this.timestamp_begin);
    first = false;
    if (!first) sb.append(", ");
    sb.append("timestamp_end:");
    sb.append(this.timestamp_end);
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, java.lang.ClassNotFoundException {
    try {
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class KeepAliveResStandardSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public KeepAliveResStandardScheme getScheme() {
      return new KeepAliveResStandardScheme();
    }
  }

  private static class KeepAliveResStandardScheme extends org.apache.thrift.scheme.StandardScheme<KeepAliveRes> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, KeepAliveRes struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // ERROR_CODE
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.error_code = iprot.readI32();
              struct.setError_codeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // ERROR_TEXT
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.error_text = iprot.readString();
              struct.setError_textIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // ID
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.id = iprot.readI32();
              struct.setIdIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // TIMESTAMP_BEGIN
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.timestamp_begin = iprot.readI64();
              struct.setTimestamp_beginIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 5: // TIMESTAMP_END
            if (schemeField.type == org.apache.thrift.protocol.TType.I64) {
              struct.timestamp_end = iprot.readI64();
              struct.setTimestamp_endIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, KeepAliveRes struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldBegin(ERROR_CODE_FIELD_DESC);
      oprot.writeI32(struct.error_code);
      oprot.writeFieldEnd();
      if (struct.error_text != null) {
        oprot.writeFieldBegin(ERROR_TEXT_FIELD_DESC);
        oprot.writeString(struct.error_text);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(ID_FIELD_DESC);
      oprot.writeI32(struct.id);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(TIMESTAMP_BEGIN_FIELD_DESC);
      oprot.writeI64(struct.timestamp_begin);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(TIMESTAMP_END_FIELD_DESC);
      oprot.writeI64(struct.timestamp_end);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class KeepAliveResTupleSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public KeepAliveResTupleScheme getScheme() {
      return new KeepAliveResTupleScheme();
    }
  }

  private static class KeepAliveResTupleScheme extends org.apache.thrift.scheme.TupleScheme<KeepAliveRes> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, KeepAliveRes struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol oprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet optionals = new java.util.BitSet();
      if (struct.isSetError_code()) {
        optionals.set(0);
      }
      if (struct.isSetError_text()) {
        optionals.set(1);
      }
      if (struct.isSetId()) {
        optionals.set(2);
      }
      if (struct.isSetTimestamp_begin()) {
        optionals.set(3);
      }
      if (struct.isSetTimestamp_end()) {
        optionals.set(4);
      }
      oprot.writeBitSet(optionals, 5);
      if (struct.isSetError_code()) {
        oprot.writeI32(struct.error_code);
      }
      if (struct.isSetError_text()) {
        oprot.writeString(struct.error_text);
      }
      if (struct.isSetId()) {
        oprot.writeI32(struct.id);
      }
      if (struct.isSetTimestamp_begin()) {
        oprot.writeI64(struct.timestamp_begin);
      }
      if (struct.isSetTimestamp_end()) {
        oprot.writeI64(struct.timestamp_end);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, KeepAliveRes struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol iprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet incoming = iprot.readBitSet(5);
      if (incoming.get(0)) {
        struct.error_code = iprot.readI32();
        struct.setError_codeIsSet(true);
      }
      if (incoming.get(1)) {
        struct.error_text = iprot.readString();
        struct.setError_textIsSet(true);
      }
      if (incoming.get(2)) {
        struct.id = iprot.readI32();
        struct.setIdIsSet(true);
      }
      if (incoming.get(3)) {
        struct.timestamp_begin = iprot.readI64();
        struct.setTimestamp_beginIsSet(true);
      }
      if (incoming.get(4)) {
        struct.timestamp_end = iprot.readI64();
        struct.setTimestamp_endIsSet(true);
      }
    }
  }

  private static <S extends org.apache.thrift.scheme.IScheme> S scheme(org.apache.thrift.protocol.TProtocol proto) {
    return (org.apache.thrift.scheme.StandardScheme.class.equals(proto.getScheme()) ? STANDARD_SCHEME_FACTORY : TUPLE_SCHEME_FACTORY).getScheme();
  }
}

